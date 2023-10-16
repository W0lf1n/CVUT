#include <stdio.h>


// Struktura seskupuje ruzne souvisejici datove polozky do jedne logicke jednotky
// Kazda polozka v 'struct' ma svuj vlastni datovy typ
// Nazev struktury je definovan na konci - v vem pripade 'TrainSchedule'
typedef struct {
    char arrival[6];
    char departure[6];
} TrainSchedule;

int main(){
    // Zde vytvarim instance struktury TrainSchedule
    // Kazda z techto instanci uklada sve vladni kopie clenu
    TrainSchedule trains[3];
    char* trainNames[] = {"A", "B", "C"};

    // Tento for prochazi array vlaku
    for (int i = 0; i < 3; i++){
        // Vypisuje cas prijezdu vlaku pro specificke jmeno vlaku dle indexu v array
        printf("Cas prijezdu vlaku %s:\n", trainNames[i]);
        // Cte uzivatelsky input na standartnim vstupu - stdin
        // a uklada jej do clenu 'arrival' aktualniho vlaku z pole 'trains[i]'
        fgets(trains[i].arrival, sizeof(trains[i].arrival), stdin);

        // Vypisuje cas prijezdu vlaku pro specificke jmeno vlaku dle indexu v array
        printf("Cas odjezdu vlaku %s:\n", trainNames[i]);
        // Cte uzivatelsky input, uklada jej do clenu 'departure' aktualniho vlaku z pole
        fgets(trains[i].departure, sizeof(trains[i].departure), stdin);
    }

}
