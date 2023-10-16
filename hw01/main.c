#include <stdio.h>
#include <stdbool.h>

// Struktura seskupuje ruzne souvisejici datove polozky do jedne logicke jednotky
// Kazda polozka v 'struct' ma svuj vlastni datovy typ
// Nazev struktury je definovan na konci - v vem pripade 'TrainSchedule'
typedef struct {
    char arrival[6];
    char departure[6];
} TrainSchedule;

// This function handle the time format validation
// sscanf function is used to parse the hour and minute from the input string 'timeStr'
// The format string '"%2d:%2d"' ensures this format - 00:00
bool validateTimeFormat(char *timeStr){
    int hour, minute;
    // This IF returns false if the scanned items is not equal to 2
    //          - one for hours, one for minutes
    if (sscanf(timeStr, "%2d:%2d", $hour, $minute) != 2){
        return false;
    }
    // This IF checks if the time is in right format
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59){
        return false;
    }
    return true;
}

// Funkce ma na vstupu 2 argumenty
//      'prompt' je pointer na text, ktery chceme uzivateli zobrazit
//      'timeStr' je pointer, do ktereho se uklada uzivatelsky vstup
void getTimeInput(char *prompt, char *timeStr){
    // Vypisuje zpravu uzivateli
    printf("%s", prompt); 

    // Cte uzivatelsky vstup na standartnim vstupu - stdin
    fgets(timeStr, 6, stdin);

    // Pokud vstup je nespravny, informuje uzivatele
    if (!isValidTimeFormat(timeStr)) {
        printf("Nespravny vstup.\n");
    }
}

int main(){
    // Zde vytvarim instance struktury TrainSchedule
    // Kazda z techto instanci uklada sve vladni kopie clenu
    TrainSchedule trains[3];
    char* trainNames[] = {"A", "B", "C"};

    // Tento for prochazi array vlaku
    for (int i = 0; i < 3; i++) {
        // buffer pro ulozeni retezce vyzvy 
        char prompt[30];

        // Toto vytvori retezec s vyzvou k zadani casu
        // trainNames[i] zahrne do zpravy jmeno vlaku, ktereho se cas tyka
        sprintf(prompt, "Cas prijezdu vlaku %s:\n", trainNames[i]);
        getTimeInput(prompt, trains[i].arrival);

        sprintf(prompt, "Cas odjezdu vlaku %s:\n", trainNames[i]);
        getTimeInput(prompt, trains[i].departure);
    }
    return 0;
}
