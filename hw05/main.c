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

void addReview(struct myReviews **reviews, char *input, int *reviewCount) {

    struct myReviews newReview;
    sscanf(input, "%d-%d-%d %d %[^\n]", &newReview.year,
                                        &newReview.month,
                                        &newReview.day,
                                        &newReview.rating,
                                        newReview.reviewName);

    *reviews = (struct myReviews *)realloc(*reviews, (*reviewCount + 1) * sizeof(struct myReviews));
    (*reviews)[*reviewCount] = newReview;
    (*reviewCount)++;
}

void printReviews(struct myReviews **reviews, char *input, int reviewCount) {
    if (*reviews == NULL){
        printf("Nespravny vstup.");
        exit(1);
    }
    int targetRating = atoi(input);
    int closestDifference = INT_MAX;
    int closestYear = 0, closestMonth = 0, closestDay = 0;
    int closestTotalRating = 0;
    int i, j;

    for (i = 0; i < reviewCount; i++) {
        int totalRating = 0;
        int year = (*reviews)[i].year;
        int month = (*reviews)[i].month;
        int day = (*reviews)[i].day;

        for (j = i; j < reviewCount && (*reviews)[j].year == year && (*reviews)[j].month == month && (*reviews)[j].day == day; j++) {
            totalRating += (*reviews)[j].rating;
        }

        int currentDifference = abs(totalRating - targetRating);
        if (currentDifference < closestDifference) {
            closestDifference = currentDifference;
            closestYear = year;
            closestMonth = month;
            closestDay = day;
            closestTotalRating = totalRating;
        }
        i = j - 1;
    }
    printf("%d-%02d-%02d: %d\n", closestYear, closestMonth, closestDay, closestTotalRating);
}

void getUserInput() {
    struct myReviews *reviews = NULL;
    char inputLine[4096];
    int reviewCount = 0;

    while (fgets(inputLine, sizeof(inputLine), stdin) != NULL){
        switch(inputLine[0]){
            case '+':
                printf("Ulozeno!\n");
                addReview(&reviews, inputLine + 2, &reviewCount);
                break;
            case '?':
                printf("Vypsano full\n");
                break;
            case '#':
                printf("Vypsano\n");
                printReviews(&reviews, inputLine + 2, reviewCount);
                break;
            default:
                printf("Nespravny vstup.\n");
                break;
        }
    }
    free(reviews);
}

int main() {
   printf("Recenze:\n");
   getUserInput();

   return 1;
}
