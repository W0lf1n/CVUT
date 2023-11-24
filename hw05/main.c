#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

struct myReviews {
    int year;
    int month;
    int day;
    int rating;
    char reviewName[4096];
};

struct dateSum {
    int year;
    int month;
    int day;
    int totalRating;
};

void sortDateSum(struct dateSum *ratings, int ratingCount) {
    for (int i = 0; i < ratingCount - 1; i++) {
        for (int j = 0; j < ratingCount - i - 1; j++) {
            if (ratings[j].totalRating < ratings[j + 1].totalRating) {
                struct dateSum temp = ratings[j];
                ratings[j] = ratings[j + 1];
                ratings[j + 1] = temp;
            }
        }
    }
}


void addReview(struct myReviews **reviews, struct dateSum **ratings, char *input, int *reviewCount, int *ratingCount, int *isSorted) {

    struct myReviews newReview;
    sscanf(input, "%d-%d-%d %d %[^\n]", &newReview.year,
                                        &newReview.month,
                                        &newReview.day,
                                        &newReview.rating,
                                        newReview.reviewName);

    static int lastYear, lastMonth, lastDay = 0;
    if(lastYear != 0 || lastMonth != 0 || lastDay != 0){
        if(lastYear > newReview.year ||
                lastMonth > newReview.month ||
                lastDay > newReview.day){
            printf("Nespravny vstup.\n");
            exit(1);
        }
    }
    lastYear = newReview.year;
    lastMonth = newReview.month;
    lastDay = newReview.day;


    if (*ratingCount > 0 && (*ratings)[*ratingCount - 1].year == newReview.year 
            && (*ratings)[*ratingCount - 1].month == newReview.month 
            && (*ratings)[*ratingCount - 1].day == newReview.day) {
        (*ratings)[*ratingCount - 1].totalRating += newReview.rating;
    } else {
        *ratings = (struct dateSum *)realloc(*ratings, (*ratingCount + 1) * sizeof(struct dateSum));
        (*ratings)[*ratingCount].year = newReview.year;
        (*ratings)[*ratingCount].month = newReview.month;
        (*ratings)[*ratingCount].day = newReview.day;
        (*ratings)[*ratingCount].totalRating = newReview.rating;
        (*ratingCount)++;
    }


    *reviews = (struct myReviews *)realloc(*reviews, (*reviewCount + 1) * sizeof(struct myReviews));
    (*reviews)[*reviewCount] = newReview;
    (*reviewCount)++;

    *isSorted = 0;
}


void printReviews(struct dateSum **ratings, char *input, int *ratingCount, int *isSorted) {
    if (*ratings == NULL || *ratingCount == 0) {
        printf("Nespravny vstup.\n");
        return;
    }
    if (!*isSorted) {
        sortDateSum(*ratings, *ratingCount);
        *isSorted = 1;
    }

    int targetRating = atoi(input);
    int closestDifference = INT_MAX;
    int startYear = 0, startMonth = 0, startDay = 0;
    int endYear = 0, endMonth = 0, endDay = 0;
    int closestTotalRating = 0;

    for (int i = *ratingCount - 1; i >= 0; i--) {
        int totalRating = 0;

        for (int j = i; j >= 0; j--) {
            totalRating += (*ratings)[j].totalRating;
            int currentDiff = abs(totalRating - targetRating);

            if (currentDiff < closestDifference) {
                closestDifference = currentDiff;
                closestTotalRating = totalRating;
                startYear = (*ratings)[j].year;
                startMonth = (*ratings)[j].month;
                startDay = (*ratings)[j].day;
                endYear = (*ratings)[i].year;
                endMonth = (*ratings)[i].month;
                endDay = (*ratings)[i].day;
            }

            if (totalRating >= targetRating) {
                break;
            }
        }
    }

    printf("%d-%02d-%02d - %d-%02d-%02d: %d\n", startYear, startMonth, startDay, endYear, endMonth, endDay, closestTotalRating);
}



void getUserInput() {
    struct myReviews *reviews = NULL;
    struct dateSum *ratings = NULL;
    char inputLine[4096];
    int reviewCount = 0;
    int ratingCount = 0;
    int isSorted = 1;
    while (fgets(inputLine, sizeof(inputLine), stdin) != NULL){
        switch(inputLine[0]){
            case '+':
                printf("Ulozeno!\n");
                addReview(&reviews, &ratings, inputLine + 2, &reviewCount, &ratingCount, &isSorted);
                break;
            case '?':
                printf("Vypsano full\n");
                break;
            case '#':
                printReviews(&ratings, inputLine + 2, &ratingCount, &isSorted);
                break;
            default:
                printf("Nespravny vstup.\n");
                break;
        }
    }
    free(reviews);
    free(ratings);
}

int main() {
   printf("Recenze:\n");
   getUserInput();

   return 1;
}
