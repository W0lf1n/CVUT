#include <stdio.h>
#include <stdlib.h>


/**
 * Struktura pro ukládání časů příjezdu a odjezdu vlaků
 * Časy jsou ukládány ve formátu minut od půlnoci
 */
typedef struct {
    int arrival;
    int departure;
} TrainSchedule;



/**
 * Funkce načte od uživatele časy příjezdu a odjezdu pro specifický vlak a uloží je do struktury
 *
 * @param train Ukazatel na strukturu TrainSchedule, kam se uloží časy příjezdu a odjezdu
 * @param name Ukazatel na řetězec reprezenzující název vlaku
 */
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

/**
 * Funkce zkontroluje, zda je možné přestoupit z vlaku 'from' na vlak 'to' v rozmezí 5 až 180 minut
 *
 * @param from Ukazatel na strukturu TrainSchedule = vlak ze ktereho se prestupuje
 * @param to Ukazatel na struktuur TrainSchedule = vlak na ktery se prestupuje
 * @return Vrací 1, pokud je přestup možný, a 0, pokud není
 */
int canTransfer(TrainSchedule* from, TrainSchedule* to) {
    int transferTimeDeparture = to->departure - from->arrival;
    int transferTimeArrival = to->arrival - from->arrival;

    if (transferTimeDeparture < 0) transferTimeDeparture += 24 * 60;
    if (transferTimeArrival < 0) transferTimeArrival += 24 * 60;

    return ((transferTimeDeparture >= 5 && transferTimeDeparture <= 180) ||
            (transferTimeArrival >= 5 && transferTimeArrival <= 180));
}


/**
 * Funkce najde a vypíše možné přestupy z aktuálního vlaku na ostatní vlaky.
 * Pokud jsou možné přestupy, vypíše názvy vlaků, na které lze přestoupit
 * Pokud nejsou možné žádné přestupy, vypíše, že z vlaku nelze přestupovat
 *
 * @param trains Ukazatel na pole struktur TrainSchedule reprezentující vlaky
 * @param names Ukazatel na pole názvů vlaků
 * @param currentTrain Index aktuálního vlaku v poli
 */
void findTransfers(TrainSchedule* trains, const char** names, int currentTrain) {
    int transferCount = 0;
    char transferNames[3] = ""; 

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
            if (i == transferCount - 1) {
                printf(" a %c.\n", transferNames[i]);
            } else {
                printf(", %c", transferNames[i]);
            }
        }
    }
}


/**
 * Pro každý vlak zavolá funkci getSchedule, aby načetla časy příjedu a odjezdu
 * Poté pro každý vlak zavolá funkci findTransfers, aby zjistila možné přestupy
 *
 * @return Vraci 0 po úspěšném dokončení programu
 */
int main(){
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
