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

int compareDates(struct dateSum a, struct dateSum b) {
    if (a.year != b.year) 
        return a.year - b.year;
    if (a.month != b.month) 
        return a.month - b.month;
    return a.day - b.day;
}

void sortUsedIndexesByDate(struct dateSum **ratings, int *usedIndexes, int usedCount) {
    for (int i = 0; i < usedCount - 1; i++) {
        for (int j = 0; j < usedCount - i - 1; j++) {
            if (compareDates((*ratings)[usedIndexes[j]], (*ratings)[usedIndexes[j + 1]]) > 0) {
                // Prohodíme indexy
                int temp = usedIndexes[j];
                usedIndexes[j] = usedIndexes[j + 1];
                usedIndexes[j + 1] = temp;
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

    int found = 0;
    for (int i = 0; i < *ratingCount; i++) {
        if ((*ratings)[i].year == newReview.year && 
            (*ratings)[i].month == newReview.month && 
            (*ratings)[i].day == newReview.day) {
            (*ratings)[i].totalRating += newReview.rating;
            found = 1;
            break;
        }
    }
    
    // Pokud nebylo datum nalezeno, přidáme nový záznam
    if (!found) {
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

void findCombination(struct dateSum **ratings, int currentIndex, int ratingCount, int *currentCombination, int combinationLength, int currentSum, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex, int *usedIndexes) {
    if (currentIndex == ratingCount) {
        int currentDiff = abs(currentSum - targetRating);
        if (currentDiff < abs(*bestSum - targetRating) && currentSum != 0) {
            *bestSum = currentSum;
            *bestStartIndex = -1; 
            *bestEndIndex = -1; 

            memset(usedIndexes, 0, ratingCount * sizeof(int));
            for (int i = 0; i < combinationLength; i++) {
                int idx = currentCombination[i];
                usedIndexes[idx] = 1; // Označíme index jako použitý
                if (*bestStartIndex == -1 || (*ratings)[idx].year < (*ratings)[*bestStartIndex].year ||
                    ((*ratings)[idx].year == (*ratings)[*bestStartIndex].year && (*ratings)[idx].month < (*ratings)[*bestStartIndex].month) ||
                    ((*ratings)[idx].year == (*ratings)[*bestStartIndex].year && (*ratings)[idx].month == (*ratings)[*bestStartIndex].month && (*ratings)[idx].day < (*ratings)[*bestStartIndex].day)) {
                    *bestStartIndex = idx;
                }
                if (*bestEndIndex == -1 || (*ratings)[idx].year > (*ratings)[*bestEndIndex].year ||
                    ((*ratings)[idx].year == (*ratings)[*bestEndIndex].year && (*ratings)[idx].month > (*ratings)[*bestEndIndex].month) ||
                    ((*ratings)[idx].year == (*ratings)[*bestEndIndex].year && (*ratings)[idx].month == (*ratings)[*bestEndIndex].month && (*ratings)[idx].day > (*ratings)[*bestEndIndex].day)) {
                    *bestEndIndex = idx;
                }
            }
        }
        return;
    }

    currentCombination[combinationLength] = currentIndex;
    findCombination(ratings, currentIndex + 1, ratingCount, currentCombination, combinationLength + 1, currentSum + (*ratings)[currentIndex].totalRating, targetRating, bestSum, bestStartIndex, bestEndIndex, usedIndexes);
    findCombination(ratings, currentIndex + 1, ratingCount, currentCombination, combinationLength, currentSum, targetRating, bestSum, bestStartIndex, bestEndIndex, usedIndexes);
}


void findBestCombination(struct dateSum **ratings, int ratingCount, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex, int **usedIndexes) {
    *usedIndexes = (int *)calloc(ratingCount, sizeof(int));
    int *currentCombination = (int *)malloc(ratingCount * sizeof(int)); 
    *bestSum = INT_MAX;
    *bestStartIndex = -1;
    *bestEndIndex = -1;

    findCombination(ratings, 0, ratingCount, currentCombination, 0, 0, targetRating, bestSum, bestStartIndex, bestEndIndex, *usedIndexes);

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
    int *usedIndexes = NULL;

    findBestCombination(ratings, *ratingCount, targetRating, &bestSum, &bestStartIndex, &bestEndIndex, &usedIndexes);

    if (usedIndexes != NULL) {
        free(usedIndexes); 
    }

    if (bestStartIndex != -1) {
        printf("%d-%02d-%02d - %d-%02d-%02d: %d\n",
              (*ratings)[bestStartIndex].year, (*ratings)[bestStartIndex].month, (*ratings)[bestStartIndex].day,
              (*ratings)[bestEndIndex].year, (*ratings)[bestEndIndex].month, (*ratings)[bestEndIndex].day,
              bestSum);
    }
}  


    void printFullReviews(struct dateSum **ratings, struct myReviews **reviews, int reviewCount, int ratingCount, int targetRating) {
    int bestSum, bestStartIndex, bestEndIndex;
    int *usedIndexes;

    findBestCombination(ratings, ratingCount, targetRating, &bestSum, &bestStartIndex, &bestEndIndex, &usedIndexes);

    if (usedIndexes != NULL) {
        // Seřazení usedIndexes podle data
        int usedCount = 0;
        for (int i = 0; i < ratingCount; i++) {
            if (usedIndexes[i]) {
                usedIndexes[usedCount++] = i;
            }
        }
        sortUsedIndexesByDate(ratings, usedIndexes, usedCount);

        // Výpis
        printf("%d-%02d-%02d - %d-%02d-%02d: %d\n",
               (*ratings)[bestStartIndex].year, (*ratings)[bestStartIndex].month, (*ratings)[bestStartIndex].day,
               (*ratings)[bestEndIndex].year, (*ratings)[bestEndIndex].month, (*ratings)[bestEndIndex].day,
               bestSum);

        for (int i = 0; i < usedCount; i++) {
            int idx = usedIndexes[i];
            // Pro každé datum vypíšeme odpovídající recenze
            for (int j = 0; j < reviewCount; j++) {
                if ((*reviews)[j].year == (*ratings)[idx].year && 
                    (*reviews)[j].month == (*ratings)[idx].month && 
                    (*reviews)[j].day == (*ratings)[idx].day) {
                    printf("  %d: %s\n", (*reviews)[j].rating, (*reviews)[j].reviewName);
                }
            }
        }
        free(usedIndexes);
    }
}


void printAllDateSums(struct dateSum *dates, int count){
    for (int i = 0; i < count; i++) {
        printf("%d-%02d-%02d: Total Rating = %d\n",
               dates[i].year, dates[i].month, dates[i].day, dates[i].totalRating);
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
                 printAllDateSums(ratings, ratingCount);
                 printFullReviews(&ratings, &reviews, reviewCount, ratingCount, atoi(inputLine + 2));
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
