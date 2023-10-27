#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * @brief Prints the synchronization time or a failure message
 *
 * @param synchronization_time The calculated sync. time
 *
 */
void outputResult(long long int synchronization_time) {
    if (synchronization_time >= 0) {
        printf("Synchronizace za: %lld\n", synchronization_time);
    } else {
        printf("Nelze dosahnout.\n");
    }
}


/**
 * @brief Calculates the Greatest Common Divisor (GCD) of two numbers
 *
 * @param a The sum of message units for the first message
 * @param b The sum of message units for the second message
 * @return The GCD of the two input sums
 */
long long int GCD(long long int a, long long int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

//long long int LCM(long long int a, long long int b) {
//    return (a * b) / GCD(a, b);
//}

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
long long int findSynchronizationTime(long long int previous_sync_time, long long int message_sum_before, long long int message_sum_after) {
    long long int step_message_current = message_sum_before + message_sum_after;  // Step for the current message
    long long int lcm_result = (previous_sync_time * step_message_current) / GCD(previous_sync_time, step_message_current);

    for (long long int t = previous_sync_time; t <= lcm_result; t += previous_sync_time) {
        if ((t - message_sum_before) % step_message_current == 0) {
            return t;
        }
    }

    return -1;  // If synchronization is not possible
}





/**
 * @brief Processes the input, help validates it, and help calculates the sync. time
 *
 * This function reads the input, computes the sum of units before and after '|'
 * and handles different scenarios to output the result
 */
void processAndValidateInput() {
    printf("Zpravy:\n");

    long int message_count = 0;
    long long int char_count = 0;  // Počet znaků ve zprávě
    int pipe_count = 0;  // Počet znaků '|' ve zprávě
    long long int message_sum_before = 0;  // Součet jednotek před '|'
    long long int message_sum_after = 0;  // Součet jednotek po '|'
    long long int GCD_result;
    long long int sync_time;
    long long int previous_sync_time = 0;
    long long int first_message_sum_before;
    long long int first_message_sum_after;

    char ch;
    while ((ch = fgetc(stdin)) != EOF) {

        if (ch == '\n') {
            message_count++;

            GCD_result = GCD(message_sum_before + message_sum_after, message_sum_before + message_sum_after);
            if ((message_sum_before - message_sum_before) % GCD_result != 0){
                outputResult(-1);
                return;
            }
            // Check if the | is on end or start of the message
            for (int i = 0; i < message_count; i++) {
                    if (char_count == pipe_count || message_sum_before == 0 || message_sum_after == 0) {
                    outputResult(0);
                    return;
                }
            }
            
            if (char_count == 0 || char_count == pipe_count) {
                printf("Nespravny vstup.\n");
                exit(1);
            }

            if (message_count == 1) {
                first_message_sum_before = message_sum_before;
                first_message_sum_after = message_sum_after;
            } else if (message_count == 2) {

                long long int first_message_step = first_message_sum_before + first_message_sum_after;
                long long int second_message_step = message_sum_before + message_sum_after;

                long long int gcd_result = GCD(first_message_step, second_message_step);

                if ((first_message_sum_before - message_sum_before) % gcd_result != 0){
                    outputResult(-1);
                    return;
                }


                long long int lcm_result = (first_message_step / gcd_result) * second_message_step;

                for (long long int t = first_message_sum_before; t <= lcm_result; t += first_message_step) {
                    if ((t - message_sum_before) % second_message_step == 0){
                        previous_sync_time = t;
                    }
                }

                for (long long int t = message_sum_before; t <= lcm_result; t += second_message_step){
                    if ((t - first_message_sum_before) % first_message_step == 0){
                        previous_sync_time = t;
                    }
                }

            } else {
                    sync_time = findSynchronizationTime(previous_sync_time, message_sum_before, message_sum_after);
                if (sync_time == -1) {
                    outputResult(-1);
                    return;
                }
                previous_sync_time = sync_time;
            }

            char_count = 0;
            pipe_count = 0;
            message_sum_before = 0;
            message_sum_after = 0;
        } else {
            char_count++;
            if (ch == '|') {
                pipe_count++;
                if (pipe_count > 1){
                    printf("Nespravny vstup.\n");
                    exit(1);
                }
            } else if (ch == ' ') {
                printf("Nespravny vstup.\n");
                exit(1);
            } else if (islower(ch) || ch == '|') {
                long long int pulse_length = 1 << (ch - 'a');  // Char to specific number
                if (pipe_count == 0) {  // Before '|'
                    message_sum_before += pulse_length;
                } else {  // After '|'
                    message_sum_after += pulse_length;
                }
            } else {
                printf("Nespravny vstup.\n");
                exit(1);
            }
        }
    }

    if (message_count < 2){
        printf("Nespravny vstup.\n");
        exit(1);
    }

    sync_time = previous_sync_time;
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
