#include <stdio.h>

int main() {
    int x, y, z;

    //Declares an array of type char with 20 elements
    // - user input will not be bigger that 20 elements in this case
    char input[20];

    printf("Enter RGB values in format 'rgb ( x, y, z )' where x, y, z are integers in range from 0 to 255.\n");

    // FGETS reads the entire line of input - including whitespaces - from specified stram - STDIN
    // STDIN represents standart input, and stores it in the string pointed to the first argument - INPUT
    // 20 specifies the maximum number of characters to be read
    fgets(input, 20, stdin);

    // SSCANF reads data from the string - INPUT in this case
    // and stores the values into the specific variables - X, Y, Z
    // SCANF stops reading input as soon as it encounters whitespace - thats why I use SSCANF
    sscanf(input, "rgb ( %d, %d, %d )", &x, &y, &z);


    if((x >= 0 && x <= 255) && (y >= 0 && y <= 255) && (z >= 0 && z <= 255)) {
        // Input is valid
    } else {
        printf("Invalid input. RGB values must be between 0 and 255.\n");
    }

    return 0;
}

