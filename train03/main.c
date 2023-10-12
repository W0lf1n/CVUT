#include <stdio.h>
#include <string.h>
#include <ctype.h>

// This function will remove any whitespaces from the given string
void remove_whitespaces(char* str){
    // A new pointer 'dest' is initialized to point to the beginning of the given string
    char* dest = str;
    // While loop which iterated through the string char-by-char
    while(*str){
        // The ISSPACE function checks if the current character is a whitespace
        if(!isspace(*str)){
            // If the current char is not a whitespace,
            // it is copied to the location on which *dest currently pointing
            // Then the *dest pointer is incremented to the next location
            *dest++ = *str;
        }
        str++;
    }
    // After the loop has processed all chars
    // a null terminator is writter to the end of the string
    *dest = '\0';
}

int main() {
    int r, g, b;

    // Declares an array of type char with 50 elements
    // - user input will not be bigger that 50 elements in this case
    char input[50], formatted[50];

    printf("Zadejte barvu v RGB formatu:\n");

    // FGETS reads the entire line of input - including whitespaces - from specified stram - STDIN
    // STDIN represents standart input, and stores it in the string pointed to the first argument - INPUT
    // 50 specifies the maximum number of characters to be read
    fgets(input, 50, stdin);

    // SSCANF reads data from the string - INPUT in this case
    // and stores the values into the specific variables - X, Y, Z
    // SCANF stops reading input as soon as it encounters whitespace - thats why I use SSCANF
    sscanf(input, " rgb ( %d , %d , %d ) ", &r, &g, &b);
    
    // SNPRINTF function is used for formatted string output
    // - FORMATTED is the destination buffer where the formatted string will be writter to
    // - 50 is the maximum number of chars to be written to the buffer
    // - the rest is format string
    snprintf(formatted, 50, "rgb(%d,%d,%d)", r, g, b);

    // Function that normalize the user input
    remove_whitespaces(input);

    // If every number is in 0-255 range 
    // and input from the user match the required input
    // it will display the hexadecimal number 
    if(((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255)) 
            && (strcmp(input, formatted)) == 0 ) {
        // String to hold the hexadecimal representation (7 + 1 null terminator)
        char hex[8];

        // SNPRINTF function is used for formatted string output
        // - HEX is the destination buffer where the formatted string will be stored
        // - %02X is the placeholder for int value formatted as a two-digit hexadecimal number
        snprintf(hex, 8, "#%02X%02X%02X", r, g, b);
        printf("%s\n", hex);
    } else {
        printf("Nespravny vstup.\n");
    }
    return 0;
}


