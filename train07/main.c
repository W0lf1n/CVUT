#include <stdio.h>
#include <stdlib.h>

/**
 * Structure to hold information about political parties,
 * their vote counts, and the number of seats to be allocated.
 */
struct politicalParties {
    int parties;
    char party_name[26];
    int party_votes[26];
    int miners;
};

/**
 * Reads and validates input for the number of parties, their names, vote counts,
 * and the number of seats to be allocated.
 * 
 * @param data Pointer to the structure holding the election data.
 */
void readInput(struct politicalParties *data){
    /** Reads input for PARTIES **/
    printf("Pocet stran:\n");
    scanf("%d", &data->parties);

    if(data->parties < 2 || data->parties > 26){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    /******************************/

    /** Reads input for PARTY NAMES & VOTES **/
    printf("Strany a pocet hlasu:\n");
    for(int i = 0; i < data->parties; i++){
        char party;
        int votes;

        if(scanf(" %c %d", &party, &votes) != 2){
            printf("Nespravny vstup.\n");
            exit(1);
        }

        if(party < 'A' || party >= 'A' + data->parties || votes <= 0){
            printf("Nespravny vstup.\n");
            exit(1);
        }

        // Kontrola duplicity názvů stran
        for (int j = 0; j < i; j++) {
            if (data->party_name[j] == party) {
                printf("Nespravny vstup.\n");
                exit(1);
            }
        }
        data->party_name[i] = party;
        data->party_votes[i] = votes;
    }
    /******************************************/

    /** Reads input for MINERS **/
    printf("Pocet horniku:\n");
    if(scanf("%d", &data->miners) != 1){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    if(data->miners <= 1){
        printf("Nelze rozdelit.\n");
        exit(1);
    }
    /*****************************/
}


/**
 * Implements the D'Hondt method for seat allocation based on the number of votes.
 * Allocates seats to parties and prints the allocation results.
 * 
 * @param data Pointer to the structure containing the election data.
 */
void DHondtMethod(struct politicalParties *data){
    int *seats = (int *)malloc(data->parties * sizeof(int));
    double *preference = (double *)malloc(data->parties * sizeof(double));

    for(int i = 0; i < data->parties; i++){
        seats[i] = 0;
        preference[i] = (double)data->party_votes[i] / 1.42;
    }

    for(int i = 0; i < data->miners; i++){
        int maxIndex = 0;
        for(int j = 0; j < data->parties; j++){
            if(preference[j] > preference[maxIndex]){
                maxIndex = j;
            }
        }

        seats[maxIndex]++;
        preference[maxIndex] = (double)data->party_votes[maxIndex] / (1 + seats[maxIndex]);
    }

    printf("Pridelene pocty:\n");
    for (char ch = 'A'; ch < 'A' + data->parties; ch++) {
        for (int i = 0; i < data->parties; i++) {
            if (data->party_name[i] == ch) {
                printf("%c: %d\n", ch, seats[i]);
                break;
            }
        }
    }
        
    free(seats);
    free(preference);
}


/**
 * Main function: reads input data and computes seat allocation.
 */
int main (){
    struct politicalParties data;
    
    readInput(&data);
    DHondtMethod(&data);

    return 0;
}
