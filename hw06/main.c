#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * @brief Structure representing a phonebook record.
 * 
 * This structure contains a telephone number and a dynamically allocated name.
 */
typedef struct phonebook {
    char telNumber[21];
    char *name;
} Phonebook;

/**
 * @brief Converts a T9 digit to its corresponding letters.
 * 
 * @param digit A character representing a T9 digit.
 * @return A string of characters corresponding to the T9 digit.
 */
const char *t9ToLetters(char digit) {
    switch (digit) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        case '1': return " ";
        default:  return ""; 
    }
}

/**
 * @brief Adds a new phonebook record.
 * 
 * Extracts the telephone number and name from the input line,
 * checks for duplicates, and adds the record to the phonebook array.
 * 
 * @param inputLine The input line containing the phonebook record.
 * @param phonebookArray Pointer to the array of phonebook records.
 * @param phonebookSize Pointer to the size of the phonebook array.
 */
void addToPhonebook(char *inputLine, Phonebook **phonebookArray, int *phonebookSize){
    char tempTelNumber[22];
    char *nameStart;
    // Check for the required pattern
    if (inputLine[0] == ' ') {
        printf("Nespravny vstup.\n");
        return;
    }

    // Extract the phone number into a temporary buffer
    if (sscanf(inputLine, "%21s", tempTelNumber) != 1) {
        printf("Nespravny vstup.\n");
        return;
    }

    // Check if the number contains only digits
    for (char *p = tempTelNumber; *p; p++) {
        if (!isdigit((unsigned char)*p)) {
            printf("Nespravny vstup.\n");
            return;
        }
    }

    // Check for the length of the phone number
    int telNumLength = strlen(tempTelNumber);
    if (telNumLength > 20) {
        printf("Nespravny vstup.\n");
        return;
    }

    // Find where the name part begins
    nameStart = strchr(inputLine, ' ');
    if (!nameStart || strlen(nameStart) <= 1 || nameStart[1] == '\0' || nameStart[1] == ' ') {
        printf("Nespravny vstup.\n");
        return;
    }
    for(char *p = nameStart; *p; p++){
        if(!isalpha(*p) && *p != ' '){
            printf("Nespravny vstup.\n");
            return;
        }
    }

    // Check if the name does not end with the whitespace
    char *endOfName = nameStart + strlen(nameStart) - 1;
    if (*endOfName == ' ') {
        printf("Nespravny vstup.\n");
        return;
    }
    
    // Check whether the contant exists
    for (int i = 0; i < *phonebookSize; i++) {
        if (strcmp((*phonebookArray)[i].telNumber, tempTelNumber) == 0 && 
            strcmp((*phonebookArray)[i].name, nameStart + 1) == 0) {
            printf("Kontakt jiz existuje.\n");
            return;
        }
    }
    // Allocate and update new record to the phonebook
    Phonebook *newArray = (Phonebook *)realloc(*phonebookArray, (*phonebookSize + 1) * sizeof(Phonebook));
    // Check if the allocation was successful
    if (!newArray) {
        fprintf(stderr, "Error with memory allocation.\n");
        return;
    }

    *phonebookArray = newArray;
    Phonebook *pb = &((*phonebookArray)[*phonebookSize]);
    (*phonebookSize)++;

    // Store the phone number
    strcpy(pb->telNumber, tempTelNumber);

    // Allocate memory and store the name
    pb->name = (char *)malloc(strlen(nameStart + 1) + 1);
    if (pb->name) {
        strcpy(pb->name, nameStart + 1);
    } else {
        fprintf(stderr, "Error with memory allocation.\n");
        exit(1);
    }
    printf("OK\n");
}

/**
 * @brief Checks if the search term is valid for T9 searching.
 * 
 * @param searchTerm The search term to be validated.
 * @return 1 if the search term is valid, 0 otherwise.
 */
int isValidT9SearchTerm(const char *searchTerm) {
    while (*searchTerm) {
        if (!strchr("1234567890", *searchTerm)) {
            return 0;
        }
        searchTerm++;
    }
    return 1;
}

/**
 * @brief Searches the phonebook based on a T9 search term.
 * 
 * Matches the search term against both telephone numbers and names.
 * Prints out all matching records if less than 10.
 * 
 * @param searchTerm The T9 search term.
 * @param phonebookArray The array of phonebook records.
 * @param phonebookSize The size of the phonebook array.
 */
void findInPhonebook(char *searchTerm, Phonebook *phonebookArray, int phonebookSize) {
    if (!isValidT9SearchTerm(searchTerm) || *searchTerm == '\0' || *searchTerm == ' ') {
        printf("Nespravny vstup.\n");
        return;
    }
    int matchCount = 0;
    int matchedIndexes[10]; 
    int matchedIndexCount = 0;
    int searchTermLength = strlen(searchTerm);

    for (int i = 0; i < phonebookSize; i++) {
        int match = 0;

        // If the phone number match
        if (strncmp(phonebookArray[i].telNumber, searchTerm, searchTermLength) == 0) {
            match = 1;
        } else {
            // If the T9 match
            char *name = phonebookArray[i].name;
            int j = 0;
            for (int k = 0; name[k] != '\0' && searchTerm[j] != '\0'; k++) {
                if (name[k] == ' ') continue;
                if (strchr(t9ToLetters(searchTerm[j]), tolower(name[k])) != NULL) {
                    j++;
                } else {
                    break;
                }
            }
            if (j == searchTermLength) match = 1;
        }

        if (match) {
            matchCount++;
            if (matchedIndexCount < 10) {
                matchedIndexes[matchedIndexCount++] = i;
            }
        }
    }

    if (matchCount <= 10) {
        for (int i = 0; i < matchedIndexCount; i++) {
            printf("%s %s\n", phonebookArray[matchedIndexes[i]].telNumber, phonebookArray[matchedIndexes[i]].name);
        }
    }
    printf("Celkem: %d\n", matchCount);
}




/**
 * @brief Frees all dynamically allocated memory in the phonebook.
 * 
 * @param phonebookArray The array of phonebook records.
 * @param phonebookSize The size of the phonebook array.
 */
void freePhonebook(Phonebook *phonebookArray, int phonebookSize) {
    for (int i = 0; i < phonebookSize; i++) {
        free(phonebookArray[i].name); 
    }
    free(phonebookArray);
}

/**
 * @brief Removes a newline character from the end of a string.
 * 
 * @param str The string from which the newline is to be removed.
 */
void removeNewline(char *str) {
    int length = strlen(str);
    if (length > 0 && str[length - 1] == '\n') {
        str[length - 1] = '\0';
    }
}

/**
 * @brief Processes user input for managing the phonebook.
 * 
 * Supports adding new records and searching via T9.
 */
void getUserInput(){
    char *inputLine = NULL;
    size_t size = 0;
    Phonebook *phonebookArray = NULL;
    int phonebookSize = 0;
    while(getline(&inputLine, &size, stdin) != -1){
        removeNewline(inputLine);
        if(inputLine[1] != ' '){
            printf("Nespravny vstup.\n");
            continue;
        }
        switch(inputLine[0]){
            case '+':
                addToPhonebook(inputLine + 2, &phonebookArray, &phonebookSize);
                break;
            case '?':
                findInPhonebook(inputLine + 2, phonebookArray, phonebookSize);
                break;
            default:
                printf("Nespravny vstup.\n");
                break;
        }
    }
    free(inputLine);
    freePhonebook(phonebookArray, phonebookSize);
}


int main(){
   getUserInput(); 

   return 1;
}
