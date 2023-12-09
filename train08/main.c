#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void filledGameBoard(char **gameBoard, int rows){
    for(int i = 0; i < rows; i++){
        printf("%s\n", gameBoard[i]);
    }
}

void getGameBoard(){
    int rows = 0;
    char line[1024];

    char **gameBoard = NULL;

    while(fgets(line, sizeof(line), stdin)){
        line[strcspn(line, "\n")] = 0;

        // Kontrola platnosti znaků
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] != '.' && line[i] != '*') {
                fprintf(stderr, "Nespravny vstup\n");
                // Uvolnění již alokované paměti
                for (int j = 0; j < rows; j++) {
                    free(gameBoard[j]);
                }
                free(gameBoard);
                return;
            }
        }

        // Realokace pole pro nový řádek
        char **temp = realloc(gameBoard, (rows + 1) * sizeof(char*));
        if (temp == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (int i = 0; i < rows; i++) {
                free(gameBoard[i]);
            }
            free(gameBoard);
            return;
        }
        gameBoard = temp;

        // Alokace paměti pro nový řádek a kopírování obsahu
        gameBoard[rows] = malloc(strlen(line) + 1);
        if (gameBoard[rows] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            for (int i = 0; i < rows; i++) {
                free(gameBoard[i]);
            }
            free(gameBoard);
            return;
        }
        strcpy(gameBoard[rows], line);
        rows++;
    }
    filledGameBoard(gameBoard, rows);

    // Uvolnění paměti
    for(int i = 0; i < rows; i++){
        free(gameBoard[i]);
    }    free(gameBoard);

    printf("tak cau\n");
}

int main(){
    printf("Zadejte hraci plochu:\n");
    getGameBoard();

    return 0;
}
