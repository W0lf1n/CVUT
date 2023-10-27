#include <stdio.h>
#include <stdlib.h>

int main(){
    char op = 0;
    double num1, num2, result, userResult;

    printf("Zadejte rovnici:\n");

    if (scanf("%lf %c %lf = %lf", &num1, &op, &num2, &userResult) != 4) {
        printf("Nespravny vstup.\n");
        exit(1);
    }

    switch (op) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/':
            if (num2 == 0){
                printf("Nespravny vstup.\n");
                exit(1);
            }
            result = num1 / num2;
            break;
        default:
            printf("Nespravny vstup.\n");
            exit(1);
    }

    if (result == userResult){
        printf("Rovnice je spravne.\n");
    } else {
        printf("%.2lf != %.2lf\n", result, userResult);
    }

    return 0;

}
