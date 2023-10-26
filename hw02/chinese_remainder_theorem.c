#include <stdio.h>
#include <stdlib.h>



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


// Funkce pro výpočet modulárního inverzního prvku
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
    while (a > 1) {
        if (m == 0){
            break;
        }
        q = a / m;
        t = m;
        m = a % m;
        a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;

    return x1;
}

// Funkce pro nalezení minimálního x splňujícího systém rovnic x = a[i] (mod m[i])
long long findMinX(int a[], int m[], int k) {
    long long prod = 1;
    for (int i = 0; i < k; i++) {
        if (m[i] == 0) {
            return -1;
        }
        prod *= m[i];
    }

    long long result = 0;
    for (int i = 0; i < k; i++) {
        long long pp = prod / m[i];
        int inv = modInverse(pp, m[i]);
        if (inv == -1) {
            return -1;
        }
        result += a[i] * inv * pp;
    }

    return result % prod;
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
    int a[2];
    int m[2];

    m[0] = message_sum_before[0] + message_sum_after[0];
    m[1] = message_sum_before[1] + message_sum_after[1];

    a[0] = message_sum_before[0] % m[0];
    a[1] = message_sum_before[1] % m[1];

    // Prověření, zda je řešení možné
    int gcd_result = GCD(m[0], m[1]);
    if ((a[0] - a[1]) % gcd_result != 0) {
        return -1;
    }

    int sync_time = (int)findMinX(a, m, 2);

    if (sync_time % a[0] == 0) {
        sync_time /= a[0];
    }

    return sync_time/gcd_result;
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
            if (char_count[message_count] == 0){
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
            } else if (ch == ' ') {
                space_count[message_count]++;
                printf("Nespravny vstup.\n");
                exit(1);
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

    if (message_count < 2
        || char_count[0] == 0 || pipe_count[0] != 1 || space_count[0] > 0
        || char_count[1] == 0 || pipe_count[1] != 1 || space_count[1] > 0) {
        printf("Nespravny vstup.\n");
        exit(1);
    }

    int gcd_result = GCD(message_sum_before[0]+message_sum_after[0], message_sum_before[1] + message_sum_after[1]);
    if ((message_sum_before[0] - message_sum_before[1]) % gcd_result != 0){
        printf("Nelze dosahnout.\n");
        return;
    }

    for (int i = 0; i < message_count; i++) {
        if (char_count[i] == pipe_count[i] || message_sum_before[i] == 0 || message_sum_after[i] == 0) {
            printf("Synchronizace za: 0\n");
            return;
        }
    }

    int sync_time = findSynchronizationTime(message_sum_before, message_sum_after, message_count);

    if (sync_time % message_sum_before[0] == 0) {
        sync_time /= message_sum_before[0];
    }

    printf("Synchronizace za: %d\n", sync_time);
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

