#include <stdio.h>
#include <stdlib.h>



void validateInput(int message_count, int char_count[], int pipe_count[], int space_count[]) {
    if (message_count < 2 
        || char_count[0] == 0 || pipe_count[0] != 1 || space_count[0] > 0
        || char_count[1] == 0 || pipe_count[1] != 1 || space_count[1] > 0) {
        printf("Nespravny vstup.\n");
        exit(1);
    }
}

void outputResult(int synchronization_time) {
    if (synchronization_time >= 0) {
        printf("Synchronizace za: %d\n", synchronization_time);
    } else {
        printf("Nelze dosahnout.\n");
    }
}


int GCD(int first_message_sum, int second_message_sum){
    int tmp;

    if (first_message_sum < second_message_sum){
        tmp = first_message_sum;
        first_message_sum = second_message_sum;
        second_message_sum = tmp;
    }
    while (second_message_sum > 0){
        tmp = first_message_sum % second_message_sum;
        first_message_sum = second_message_sum;
        second_message_sum = tmp;
    }
    return first_message_sum;
}


int findSynchronizationTime(int message_sum_before[], int message_sum_after[], int message_count) {

    int sync_time[2] = { (message_sum_before[0] + message_sum_after[0]) + message_sum_before[0]
        , (message_sum_before[1] + message_sum_after[1]) + message_sum_before[1] };
    int step[2] = { message_sum_before[0] + message_sum_after[0], message_sum_before[1] + message_sum_after[1] };


    while (sync_time[0] != sync_time[1]) {
        if (sync_time[0] < sync_time[1]) {
            sync_time[0] += step[0];
        } else {
            sync_time[1] += step[1];
        }
    }

    return sync_time[0];
}



void processAndValidateInput() {
    printf("Zpravy:\n");

    int message_count = 0;
    int char_count[2] = {0, 0};  // Počet znaků ve zprávě
    int pipe_count[2] = {0, 0};  // Počet znaků '|' ve zprávě
    int space_count[2] = {0, 0}; // Počet mezer ve zprávě
    int message_sum_before[2] = {0, 0};  // Součet jednotek před '|'
    int message_sum_after[2] = {0, 0};  // Součet jednotek po '|'

    while (message_count < 2) {
        char ch = fgetc(stdin);
        
        if (ch == '\n') {
            message_count++;
            if (message_count < 2) {  // Resetujte počítadla pro druhou zprávu
                char_count[message_count] = 0;
                pipe_count[message_count] = 0;
                space_count[message_count] = 0;
            }
        } else {
            char_count[message_count]++;
            if (ch == '|') {
                pipe_count[message_count]++;
            } else if (ch == ' ') {
                space_count[message_count]++;
            } else {
                int pulse_length = 1 << (ch - 'a');  // Převod znaku na časovou jednotku
                if (pipe_count[message_count] == 0) {  // Před '|'
                    message_sum_before[message_count] += pulse_length;
                } else {  // Po '|'
                    message_sum_after[message_count] += pulse_length;
                }
            }
        }
    }

    validateInput(message_count, char_count, pipe_count, space_count);  // Validace zpráv po načtení obou zpráv

    int gcd_result = GCD(message_sum_before[0]+message_sum_after[0], message_sum_before[1] + message_sum_after[1]);
    if ((message_sum_before[0] - message_sum_before[1]) % gcd_result != 0){
        outputResult(-1);
        return;
    }
    // Kontrola, zda je znak '|' na začátku nebo na konci některé zprávy
    for (int i = 0; i < message_count; i++) {
        if (char_count[i] == pipe_count[i] || message_sum_before[i] == 0 || message_sum_after[i] == 0) {
            outputResult(0);
            return;
        }
    }

    int sync_time = findSynchronizationTime(message_sum_before, message_sum_after, message_count);
    outputResult(sync_time);
}

int main() {
    processAndValidateInput();

    return 0;

}
