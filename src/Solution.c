#include <stdlib.h>
#include <stdio.h>
#include <Solution.h>

int main() {

    /// Creating int variables to keep row, cols values and array for cantinious matrix in dynamic memory
    int terrainRows = 0;
    int terrainCols = 0;
    char* terrainBoard;

    if (scanf("%d %d", &terrainRows, &terrainCols) == 2) {
        terrainBoard = (char*) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
        readMatrix(terrainBoard, terrainRows, terrainCols);
        printMatrix(terrainBoard, terrainRows, terrainCols);
        free(terrainBoard);
    }

}


void readMatrix(char* terrainBoard, const int rows, const int cols) {
    for(int count = 0; count < rows * cols; count++) {
        scanf(" %c", &terrainBoard[count]);
    }
    terrainBoard[rows * cols] = '\0';
}

void printMatrix(char* terrainBoard, const int rows, const int cols) {
     for(int count = 0; count < rows * cols; count++) {
        if (count % cols == 0 & count != 0) printf("\n");
        printf("%c", terrainBoard[count]);
    }
    printf("\n");
}

