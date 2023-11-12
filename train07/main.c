#include <stdio.h>
#include <stdlib.h>

struct politicalParties {
    int parties;
    char party_name[26];
    int party_votes[26];
    int miners;
};

void readInput(struct politicalParties *data){
    printf("Pocet stran:\n");
    scanf("%d", &data->parties);

    if(data->parties < 2 || data->parties > 26){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    printf("Strany a pocet hlasu:\n");
    for(int i = 0; i < data->parties; i++){
        char party;
        int votes;
        scanf(" %c %d", &party, &votes);

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

    printf("Pocet horniku:\n");
    if(scanf("%d", &data->miners) != 1){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    if(data->miners <= 1){
        printf("Nejde rozdelit.\n");
        exit(1);
    }

}

int main (){
    struct politicalParties data;
    readInput(&data);

    return 0;
}
