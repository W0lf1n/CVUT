#include <stdio.h>
#include <stdlib.h>

int getDigits(int number) {
    int digits = 0;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

/*
 *
 */
int main(){
    int n;
    printf("Rozsah:\n");

    if (scanf("%d", &n) != 1 || n <= 0){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    int maxProduct = n * n;
    int width = getDigits(maxProduct) + 1;

    printf("%*c|", width - 1, ' ');  // Adjusted space before the vertical bar
    for (int i = n; i >= 1; i--) {
        printf("%*d", width, i);
    }
    printf("\n");

    // Print delimiters
    for (int i = 0; i < width - 1; i++) {
        printf("-");
    }
    printf("+");
    for (int i = 0; i < n * width; i++) {
        printf("-");
    }
    printf("\n");

    // Print table
    for (int i = 1; i <= n; i++) {
        printf("%*d|", width - 1, i);
        for (int j = n; j >= i; j--) {
            printf("%*d", width, i * j);
        }
        printf("\n");
    }

    return 0;

}
