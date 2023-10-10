#include <stdio.h>
#include <stdlib.h>

int main(){

    char input[50];
    printf("ml' nob:\n");
    scanf("%49[^\n]", input);

    // This variable is a pointer (* before variable name means pointer)
    char *endPointer;

    // strtol is a function that converts array of chars to the long int
    //          first argument is the number from the user (in this case)
    //          second argument is a endPointer variable:
    //                  program will store first char after conversion
    //                  For example:
    //                              if the input will be 123abc - pointer will store char 'a' as the first char after the number
    //          third arguemnt is 10 which is the base of the number system in which the number is represented
    //              - 10 = the decimal system is the most common  
    long num = strtol(input, &endPointer, 10);

    // In the first part of the condition, I am checking if the first char is a number
    // In the second part I am checking if it continues with some decimal number or some string`
    if ((input[0] >= '0' && input[0] <= '9') && 
        (*endPointer != '\0' && *endPointer != '\n' && *endPointer != ' ')) {
        printf("bIjatlh 'e' yImev\n");
        return 1;
    }

    // In the first step I check if the pointer does not point any char which is null, whitespace...
    // In the second step I check if strol method is not able to covert string to int
    if ((*endPointer != '\0' && *endPointer != ' ' && *endPointer != '\n') || endPointer == input) {
        printf("Neh mi\'\n");
        return 1;
    }
    
    if (num < 0 || num > 8){
        printf("Qih mi\' %s\n", input);
        return 1;
    }
    
    switch(num){
        case 0:
            printf("Qapla\'\nnoH QapmeH wo\' Qaw\'lu\'chugh yay chavbe\'lu\' \'ej wo\' choqmeH may\' DoHlu\'chugh lujbe\'lu\'.\n");
            break;

        case 1:
            printf("Qapla\'\nbortaS bIr jablu\'DI\' reH QaQqu\' nay\'.\n");
            break;

        case 2:
            printf("Qapla\'\nQu\' buSHa\'chugh SuvwI\', batlhHa\' vangchugh, qoj matlhHa\'chugh, pagh ghaH SuvwI\'\'e\'.\n");
            break;
        
        case 3:
            printf("Qapla\'\nbISeH\'eghlaH\'be\'chugh latlh Dara\'laH\'be\'.\n");
            break;
        
        case 4:
            printf("Qapla\'\nqaStaHvIS wa\' ram loS SaD Hugh SIjlaH qetbogh loD.\n");
            break;
        
        case 5:
            printf("Qapla\'\nSuvlu\'taHvIS yapbe\' HoS neH.\n");
            break;
        
        case 6:
            printf("Qapla\'\nHa\'DIbaH DaSop \'e\' DaHechbe\'chugh yIHoHQo\'.\n");
            break;
        
        case 7:
            printf("Qapla\'\nHeghlu\'meH QaQ jajvam.\n");
            break;
  
        case 8:
            printf("Qapla\'\nleghlaHchu\'be\'chugh mIn lo\'laHbe\' taj jej.\n");
            break;
        
        default:
            fprintf(stderr, "Error: Bad argument.\n");
            return 1;
        
    }
       
}
