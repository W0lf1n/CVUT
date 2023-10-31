#include <stdio.h>
#include <math.h>
#include <cfloat>

// Funkce pro relativní porovnání dvou čísel s tolerancí
int nearlyEqual(double a, double b, double epsilon) {
    double absA = fabs(a);
    double absB = fabs(b);
    double diff = fabs(a - b);

    if (a == b) { 
        return 1;
    } else if (a == 0 || b == 0 || diff < DBL_MIN) {
        return diff < (epsilon * DBL_MIN);
    } else { 
        return diff / fmin((absA + absB), DBL_MAX) < epsilon;
    }
}

void printFormatted(double value) {
    if (floor(value) == value) {
        printf("%.12g", value);
    } else {
        printf("%.2lf", value);
    }
}

int main() {
    double num1, num2, result, userResult;
    char op;

    printf("Zadejte rovnici:\n");
    if (scanf("%lf %c %lf = %lf", &num1, &op, &num2, &userResult) != 4) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    switch(op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0){
                printf("Nespravny vstup.\n");
                return 1;
            }
            double divisionResult = num1 / num2;
            if (floor(divisionResult) == divisionResult){
                result = floor(divisionResult);
            } else {
                result = divisionResult;
            }
            break;
    }

    if (nearlyEqual(result, userResult, 1e-14)) {
        printf("Rovnice je spravne.\n");
    } else {
        printFormatted(result);
        printf(" != ");
        printFormatted(userResult);
        printf("\n");
    }

    return 0;
}

