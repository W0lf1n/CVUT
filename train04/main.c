#include <stdio.h>
#include <stdlib.h>

/**
 * Function to calculate the number of digits in a given number
 */
int getDigits(int number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

/*
 * Main function to execute the program
 */
int main(){
    int n;
    printf("Rozsah:\n");

    // Check for valid input
    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    int maxProduct = n * n; // Calculate the maximum product in the table
    int width = getDigits(maxProduct) + 1; // Determine column width based on maximum product

    printf("%*c|", width - 1, ' ');
    for (int i = n; i >= 1; i--) {
        printf("%*d", width, i); // Print column labels
    }
    printf("\n");

    for (int i = 0; i < width - 1; i++) {
        printf("-"); // Print left part of the delimiter before '+'
    }
    printf("+");
    for (int i = 0; i < n * width; i++) {
        printf("-"); // Print right part of the delimiter after '+'
    }
    printf("\n");

    for (int i = 1; i <= n; i++) {
        printf("%*d|", width - 1, i); // Print the row label
        for (int j = n; j >= i; j--) {
            printf("%*d", width, i * j); // Print product
        }
        printf("\n"); // New line at the end of each row
    }

    return 0;

}
