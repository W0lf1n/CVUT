#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 * @brief Validates the input 
 *
 * @param message_count The count of messages.
 * @param char_count An array representing the count of characters in each message
 * @param pipe_count An array representing the count of '|' in each message
 * @param space_count An array representing the ocunt of whitespaces in each message
 */
void validateInput(int message_count, int char_count[], int pipe_count[], int space_count[]) {
    if (message_count < 2 
        || char_count[0] == 0 || pipe_count[0] != 1 || space_count[0] > 0
        || char_count[1] == 0 || pipe_count[1] != 1 || space_count[1] > 0) {
        printf("Nespravny vstup.\n");
        exit(1);
    }
}

/**
 * @brief Prints the synchronization time or a failure message
 *
 * @param synchronization_time The calculated sync. time
 *
 */
void outputResult(int synchronization_time) {
    if (synchronization_time >= 0) {
        printf("Synchronizace za: %d\n", synchronization_time);
    } else {
        printf("Nelze dosahnout.\n");
    }
}


/**
 * @brief Calculates the Greatest Common Divisor (GCD) of two numbers
 *
 * @param first_message_sum The sum of message units for the first message
 * @param second_message_sum The sum of message units for the second message
 * @return The GCD of the two input sums
 */
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

/**
 * @brief Calculates the synchronization time for the two messages
 *
 * This function incrementally increases the synchronization time of each message
 * until they are equal
 *
 * @param message_sum_before An array representing the sum of units before the '|' character
 * @param message_sum_after An array representing the sum of units after the '|' character
 * @param message_count The count of messages
 * @return The synchronization time at which the two messages are in sync.
 */
int findSynchronizationTime(int message_sum_before[], int message_sum_after[], int message_count) {
    int step[2] = { message_sum_before[0] + message_sum_after[0], message_sum_before[1] + message_sum_after[1] };

    int gcd_result = gcd(step[0], step[1]);
    int lcm_result = (step[0] / gcd_result) * step[1];

    for (int t = message_sum_before[0]; t <= lcm_result; t += step[0]) {
        if ((t - message_sum_before[1]) % step[1] == 0) {
            return t;
        }
    }

    for (int t = message_sum_before[1]; t <= lcm_result; t += step[1]) {
        if ((t - message_sum_before[0]) % step[0] == 0) {
            return t;
        }
    }

    return -1;
}





/**
 * @brief Processes the input, help validates it, and help calculates the sync. time
 *
 * This function reads the input, computes the sum of units before and after '|'
 * and handles different scenarios to output the result
 */
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
            if (char_count[message_count] == 0 || char_count[message_count] == pipe_count[message_count]) {
                printf("Nespravny vstup.\n");
                exit(1);
            }
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
                if (pipe_count[message_count] >= 2){
                    printf("Nespravny vstup.\n");
                        exit(1);
                }
            } else if (ch == ' ') {
                space_count[message_count]++;
                printf("Nespravny vstup.\n");
                exit(1);
            } else {
                if (islower(ch) || ch == '|') {
                    int pulse_length = 1 << (ch - 'a');  // Převod znaku na časovou jednotku
                    if (pipe_count[message_count] == 0) {  // Před '|'
                        message_sum_before[message_count] += pulse_length;
                    } else {  // Po '|'
                        message_sum_after[message_count] += pulse_length;
                    }
                } else {
                    printf("Nespravny vstup.\n");
                    exit(1);
                }
            }
        }
    }

    validateInput(message_count, char_count, pipe_count, space_count);  // Validace zpráv po načtení obou zpráv

    int gcd_result = gcd(message_sum_before[0]+message_sum_after[0], message_sum_before[1] + message_sum_after[1]);
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

/**
 * @brief The main entry point of the program
 *
 * @return 0 upon successful execution
 */
int main() {
    processAndValidateInput();

    return 0;

}
