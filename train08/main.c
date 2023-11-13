#include <stdio.h>
#include <stdlib.h>

void getGameBoard(){
    printf("Zadejte hraci plochu:\n");
    char gameBoardPiece = ' ';
    

    while(scanf(" %c", &gameBoardPiece) != EOF){
        if (gameBoardPiece != '.' && gameBoardPiece != '*'){
            printf("%s\n", &gameBoardPiece);
            printf("Nespravny vstup.\n");
            exit(0);
        }
        printf("ahoj\n");
    }
    printf("tak cau\n");
}

int main(){

    getGameBoard();

    return 0;
}
