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

void printCombination(struct dateSum **ratings, int *combination, int combinationLength, int currentSum, int targetRating) {
    if (combinationLength == 0) return;

    printf("%d-%02d-%02d", (*ratings)[combination[0]].year, (*ratings)[combination[0]].month, (*ratings)[combination[0]].day);
    for (int i = 1; i < combinationLength; i++) {
        printf(" - %d-%02d-%02d", (*ratings)[combination[i]].year, (*ratings)[combination[i]].month, (*ratings)[combination[i]].day);
    }
    printf(" = %d | %d\n", currentSum, targetRating);
}



void findCombination(struct dateSum **ratings, int currentIndex, int ratingCount, int *currentCombination, int combinationLength, int currentSum, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex, int start) {
    if (currentIndex == ratingCount) {
        printCombination(ratings, currentCombination, combinationLength, currentSum, targetRating); 
        printf("currentSum %d\n targetRating %d\n\n\n", currentSum, targetRating);

        int currentDiff = abs(currentSum - targetRating);
        if (currentDiff < abs(*bestSum - targetRating)) {
            *bestSum = currentSum;
            *bestStartIndex = start;
            *bestEndIndex = currentIndex - 1;
            printf("Got triggered <\n");
            if (currentDiff == 0) {
                // TODO
                return;
            }
        } else {
            // TODO
        }
        return; 
    }

    currentCombination[combinationLength] = currentIndex;
    findCombination(ratings, currentIndex + 1, ratingCount, currentCombination, combinationLength + 1, currentSum + (*ratings)[currentIndex].totalRating, targetRating, bestSum, bestStartIndex, bestEndIndex, start);

    // Toto volání zkusí kombinaci bez přidání aktuálního prvku
    findCombination(ratings, currentIndex + 1, ratingCount, currentCombination, combinationLength, currentSum, targetRating, bestSum, bestStartIndex, bestEndIndex, start);
}


void findBestCombination(struct dateSum **ratings, int ratingCount, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex) {
    int *currentCombination = (int *)malloc(ratingCount * sizeof(int)); // Dynamická alokace
    *bestSum = INT_MAX;
    *bestStartIndex = -1;
    *bestEndIndex = -1;

    findCombination(ratings, 0, ratingCount, currentCombination, 0, 0, targetRating, bestSum, bestStartIndex, bestEndIndex, 0);

    free(currentCombination);
}


void printReviews(struct dateSum **ratings, char *input, int *ratingCount, int *isSorted) {
    if (*ratings == NULL || *ratingCount == 0) {
        printf("Nespravny vstup.\n");
        exit(1);
    }
    if (!*isSorted) {
            sortDateSum(*ratings, *ratingCount);
        *isSorted = 1;
    }

    int targetRating = atoi(input);
    int bestSum, bestStartIndex, bestEndIndex;

    findBestCombination(ratings, *ratingCount, targetRating, &bestSum, &bestStartIndex, &bestEndIndex);

    if (bestStartIndex != -1) {
        printf("%d-%02d-%02d - %d-%02d-%02d: %d\n",
              (*ratings)[bestStartIndex].year, (*ratings)[bestStartIndex].month, (*ratings)[bestStartIndex].day,
              (*ratings)[bestEndIndex].year, (*ratings)[bestEndIndex].month, (*ratings)[bestEndIndex].day,
              bestSum);
    }
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
