#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

void getUserInput() {
    struct myReviews *reviews = NULL;
    char inputLine[4096];
    int reviewCount = 0;
    while(fgets(inputLine, sizeof(inputLine), stdin) != NULL){
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
