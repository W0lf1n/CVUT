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

int compareDates(struct dateSum a, struct dateSum b) {
    //printf("A %d-%d-%d \n B %d-%d-%d \n\n\n", a.year, a.month, a.day, b.year, b.month, b.day);
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
                //printf("Used Index Value : %d\n", usedIndexes[j]);
            }
        }
    }
}


bool isCombinationNewer(struct dateSum *ratings, int *combination, int length, int bestStartIndex, int bestEndIndex) {
    if (bestEndIndex == -1) return true;
    return compareDates(ratings[combination[length - 1]], ratings[bestEndIndex]) > 0;
}

void updateBestIndices(struct dateSum *ratings, int idx, int *bestStartIndex, int *bestEndIndex) {
    if (*bestStartIndex == -1 || compareDates(ratings[idx], ratings[*bestStartIndex]) < 0) {
        *bestStartIndex = idx;
    }
    if (*bestEndIndex == -1 || compareDates(ratings[idx], ratings[*bestEndIndex]) > 0) {
        *bestEndIndex = idx;
    }
}

int isValidDay(int year, int month, int day) {
    int maxDay;
    if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
        maxDay = 31;
    } else if (month == 2) {
        if ((year % 400 == 0 && year != 4000) || (year % 4 == 0 && year % 100 != 0)) {
            maxDay = 29;
        } else {
            maxDay = 28;
        }
    } else if (month >= 1 && month <= 12) {
        maxDay = 30;
    } else {
        return 0;
    }

    return day >= 1 && day <= maxDay;
}


void addReview(struct myReviews **reviews, struct dateSum **ratings, char *input, int *reviewCount, int *ratingCount) {

    struct myReviews newReview;
    sscanf(input, "%d-%d-%d %d %[^\n]", &newReview.year,
                                        &newReview.month,
                                        &newReview.day,
                                        &newReview.rating,
                                        newReview.reviewName);

    static int lastYear, lastMonth, lastDay = 0;

   if (!isValidDay(newReview.year, newReview.month, newReview.day)) {
        printf("Nespravny vstup.\n");
        exit(1);
    }
   if (newReview.rating == 0){
        printf("Nespravny vstup.\n");
        exit(1);
   }


    if(lastYear != 0 || lastMonth != 0 || lastDay != 0){
        if((lastYear > newReview.year) ||
                (lastYear > newReview.year && lastMonth > newReview.month) ||
                (lastYear > newReview.year && lastMonth > newReview.month && lastDay > newReview.day)) {
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

}

/*
void findCombination(struct dateSum **ratings, int currentIndex, int ratingCount, int *currentCombination, int combinationLength, int currentSum, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex, int *usedIndexes) {

    //printf("findCombination: currentIndex = %d, combinationLength = %d, currentSum = %d\n", currentIndex, combinationLength, currentSum);


    if (currentIndex == ratingCount) {
        int currentDiff = abs(currentSum - targetRating);

       if ((currentDiff < abs(*bestSum - targetRating) && (currentSum != 0)) || 
            (currentDiff == abs(*bestSum - targetRating) && isCombinationNewer(*ratings, currentCombination, combinationLength, *bestStartIndex, *bestEndIndex))) {
            *bestSum = currentSum;
            *bestStartIndex = currentCombination[0];
            *bestEndIndex = currentCombination[combinationLength - 1];

            // Aktualizace použitých indexů
            memset(usedIndexes, 0, ratingCount * sizeof(int));
            for (int i = 0; i < combinationLength; i++) {
                usedIndexes[currentCombination[i]] = 1;
            }
        }
        return;
    }

if (combinationLength == 0 || compareDates((*ratings)[currentCombination[combinationLength - 1]], (*ratings)[currentIndex]) <= 0) {
        currentCombination[combinationLength] = currentIndex;
        findCombination(ratings, currentIndex + 1, ratingCount, currentCombination, combinationLength + 1, currentSum + (*ratings)[currentIndex].totalRating, targetRating, bestSum, bestStartIndex, bestEndIndex, usedIndexes);
    }
    findCombination(ratings, currentIndex + 1, ratingCount, currentCombination, combinationLength, currentSum, targetRating, bestSum, bestStartIndex, bestEndIndex, usedIndexes);
}

*/

void findCombination(struct dateSum **ratings, int currentIndex, int ratingCount, int *currentCombination, int combinationLength, int currentSum, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex, int *usedIndexes) {
    // Kombinace musí být vždy ve vzestupném pořadí datumů
    if (combinationLength > 0 && compareDates((*ratings)[currentCombination[combinationLength - 1]], (*ratings)[currentIndex]) > 0) {
        return;
    }

    // Přidáme aktuální index do kombinace
    currentCombination[combinationLength++] = currentIndex;
    currentSum += (*ratings)[currentIndex].totalRating;

    // Pokud je součet rovný nebo přesahuje cílové hodnocení, zkontrolujeme, zda je to lepší kombinace
    if (currentSum >= targetRating) {
        int currentDiff = abs(currentSum - targetRating);
        if (currentDiff < abs(*bestSum - targetRating) || 
            (currentDiff == abs(*bestSum - targetRating) && compareDates((*ratings)[currentCombination[combinationLength - 1]], (*ratings)[*bestEndIndex]) > 0)) {
            *bestSum = currentSum;
            *bestStartIndex = currentCombination[0];
            *bestEndIndex = currentCombination[combinationLength - 1];

            memset(usedIndexes, 0, ratingCount * sizeof(int));
            for (int i = 0; i < combinationLength; i++) {
                usedIndexes[currentCombination[i]] = 1;
            }
        }
    }

    // Rekurzivní volání pro další indexy
    for (int i = currentIndex + 1; i < ratingCount; i++) {
        findCombination(ratings, i, ratingCount, currentCombination, combinationLength, currentSum, targetRating, bestSum, bestStartIndex, bestEndIndex, usedIndexes);
    }
}




void findBestCombination(struct dateSum **ratings, int ratingCount, int targetRating, int *bestSum, int *bestStartIndex, int *bestEndIndex, int **usedIndexes) {
    *usedIndexes = (int *)calloc(ratingCount, sizeof(int));
    int *currentCombination = (int *)malloc(ratingCount * sizeof(int)); 
    *bestSum = INT_MAX;
    *bestStartIndex = -1;
    *bestEndIndex = -1;

    //printf("findBestCombination: bestSum = %d, bestStartIndex = %d, bestEndIndex = %d\n", *bestSum, *bestStartIndex, *bestEndIndex);

    findCombination(ratings, 0, ratingCount, currentCombination, 0, 0, targetRating, bestSum, bestStartIndex, bestEndIndex, *usedIndexes);

    free(currentCombination);
}


void printReviews(struct dateSum **ratings, char *input, int *ratingCount) {
    if (*ratings == NULL || *ratingCount == 0) {
        printf("Nespravny vstup.\n");
        exit(1);
    }

    int targetRating = atoi(input);
    int bestSum, bestStartIndex, bestEndIndex;
    int *usedIndexes = NULL;
    //printf("printReviews: targetRating = %d\n", targetRating);


    findBestCombination(ratings, *ratingCount, targetRating, &bestSum, &bestStartIndex, &bestEndIndex, &usedIndexes);
   
    if (bestStartIndex != -1) {
        printf("%d-%02d-%02d - %d-%02d-%02d: %d\n",
              (*ratings)[bestStartIndex].year, (*ratings)[bestStartIndex].month, (*ratings)[bestStartIndex].day,
              (*ratings)[bestEndIndex].year, (*ratings)[bestEndIndex].month, (*ratings)[bestEndIndex].day,
              bestSum);
    }
    free(usedIndexes);
}  

/*
void printFullReviews(struct dateSum **ratings, struct myReviews **reviews, int reviewCount, int ratingCount, int targetRating) {
    int bestSum, bestStartIndex, bestEndIndex;
    int *usedIndexes;

    findBestCombination(ratings, ratingCount, targetRating, &bestSum, &bestStartIndex, &bestEndIndex, &usedIndexes);

    if (usedIndexes != NULL && bestStartIndex != -1 && bestEndIndex != -1) {
        printf("%d-%02d-%02d - %d-%02d-%02d: %d\n",
               (*ratings)[bestStartIndex].year, (*ratings)[bestStartIndex].month, (*ratings)[bestStartIndex].day,
               (*ratings)[bestEndIndex].year, (*ratings)[bestEndIndex].month, (*ratings)[bestEndIndex].day,
               bestSum);

        for (int i = 0; i < ratingCount; i++) {
            if (usedIndexes[i]) {
                for (int j = 0; j < reviewCount; j++) {
                    if ((*reviews)[j].year == (*ratings)[i].year && 
                        (*reviews)[j].month == (*ratings)[i].month && 
                        (*reviews)[j].day == (*ratings)[i].day) {
                        printf("  %d: %s\n", (*reviews)[j].rating, (*reviews)[j].reviewName);
                    }
                }
            }
        }
        free(usedIndexes);
    }
}
*/

void printFullReviews(struct dateSum **ratings, struct myReviews **reviews, int reviewCount, int ratingCount, int targetRating) {
    int bestSum, bestStartIndex, bestEndIndex;
    int *usedIndexes;

    findBestCombination(ratings, ratingCount, targetRating, &bestSum, &bestStartIndex, &bestEndIndex, &usedIndexes);

    
if (usedIndexes != NULL && bestStartIndex != -1 && bestEndIndex != -1) {
    printf("%d-%02d-%02d - %d-%02d-%02d: %d\n",
           (*ratings)[bestStartIndex].year, (*ratings)[bestStartIndex].month, (*ratings)[bestStartIndex].day,
           (*ratings)[bestEndIndex].year, (*ratings)[bestEndIndex].month, (*ratings)[bestEndIndex].day,
           bestSum);
/*
    for (int i = bestStartIndex; i <= bestEndIndex; i++) {
        for (int j = 0; j < reviewCount; j++) {
            if ((*reviews)[j].year == (*ratings)[i].year && 
                (*reviews)[j].month == (*ratings)[i].month && 
                (*reviews)[j].day == (*ratings)[i].day) {
                printf("  %d: %s\n", (*reviews)[j].rating, (*reviews)[j].reviewName);
            }
        }
    }
    free(usedIndexes);
    */
    for (int i = 0; i < ratingCount; i++) {
            if (usedIndexes[i]) {
                for (int j = 0; j < reviewCount; j++) {
                    if ((*reviews)[j].year == (*ratings)[i].year && (*reviews)[j].month == (*ratings)[i].month && (*reviews)[j].day == (*ratings)[i].day) {
                        printf("  %d: %s\n", (*reviews)[j].rating, (*reviews)[j].reviewName);
                    }
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
    while (fgets(inputLine, sizeof(inputLine), stdin) != NULL){
        switch(inputLine[0]){
            case '+':
                addReview(&reviews, &ratings, inputLine + 2, &reviewCount, &ratingCount);
                break;
            case '?':
                 //printAllDateSums(ratings, ratingCount);
                 printFullReviews(&ratings, &reviews, reviewCount, ratingCount, atoi(inputLine + 2));
                break;
            case '#':
                printReviews(&ratings, inputLine + 2, &ratingCount);
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
