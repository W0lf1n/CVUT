#include <stdio.h>
#include <stdlib.h>

// Struktura seskupuje ruzne souvisejici datove polozky do jedne logicke jednotky
// Kazda polozka v 'struct' ma svuj vlastni datovy typ
// Nazev struktury je definovan na konci - v vem pripade 'TrainSchedule'
typedef struct {
    int arrival;
    int departure;
} TrainSchedule;

void getSchedule(TrainSchedule* train, const char* name){
    int arrivalHours, arrivalMinutes;
    int departureHours, departureMinutes;

    printf("Cas prijezdu vlaku %s:\n", name);
    if (scanf("%d:%d", &arrivalHours, &arrivalMinutes) != 2 
            || arrivalHours < 0 || arrivalHours >= 24 
            || arrivalMinutes < 0 || arrivalMinutes >= 60) {
        printf("Nespravny vstup.\n");
        exit(1);
    }
    train->arrival = arrivalHours * 60 + arrivalMinutes;

    printf("Cas odjezdu vlaku %s:\n", name);
    if (scanf("%d:%d", &departureHours, &departureMinutes) != 2 
            || departureHours < 0 || departureHours >= 24 
            || departureMinutes < 0 || departureMinutes >= 60) {
        printf("Nespravny vstup.\n");
        exit(1);
    }
    train->departure = departureHours * 60 + departureMinutes;
}

int canTransfer(TrainSchedule* from, TrainSchedule* to){
    int transferTime = to->departure - from->arrival;
    return transferTime >= 5 && transferTime <= 180;
}


void findTransfers(TrainSchedule* trains, const char** names, int currentTrain) {
    int transferCount = 0;
    char transferNames[3] = "";  // To store the names of trains for transfer

    for (int i = 0; i < 3; ++i) {
        if (i != currentTrain && canTransfer(&trains[currentTrain], &trains[i])) {
            transferNames[transferCount] = *names[i];
            transferCount++;
        }
    }

    printf("Z vlaku %s ", names[currentTrain]);

    if (transferCount == 0) {
        printf("nelze prestupovat.\n");
    } else if (transferCount == 1) {
        printf("lze prestoupit na vlak %c.\n", transferNames[0]);
    } else {
        printf("lze prestoupit na vlaky %c", transferNames[0]);
        for (int i = 1; i < transferCount; ++i) {
            if (i == transferCount - 1) {  // Last transfer
                printf(" a %c.\n", transferNames[i]);
            } else {
                printf(", %c", transferNames[i]);
            }
        }
    }
}


int main(){
    // Zde vytvarim instance struktury TrainSchedule
    // Kazda z techto instanci uklada sve vladni kopie clenu
    TrainSchedule trains[3];
    const char* trainNames[] = {"A", "B", "C"};

    for (int i = 0; i < 3; ++i){
        getSchedule(&trains[i], trainNames[i]);
    }

    for (int i = 0; i < 3; ++i){
        findTransfers(trains, trainNames, i);
    }

    return 0;
}
