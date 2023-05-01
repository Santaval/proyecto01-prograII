#include <stdlib.h>
#include <stdio.h>
#include <Solution.h>

enum EXIT_CODES {ERR, SUCCESS, INSUFICIENT_DATA, INVALID_DATA};

int main() {

    /// Creating int variables to keep row, cols values and array for cantinious matrix in dynamic memory
    int terrainRows = 0; // matrix rows
    int terrainCols = 0; // matix cols
    char* terrainBoard; // pointer to char array in dynamic memory

    /// reading matrix dimmensions and validate them
    if (scanf("%d %d", &terrainRows, &terrainCols) == 2) {
        /// assign dynamic memory spae to keep continious matix
        terrainBoard = (char*) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
        const int readMatixReturn = readMatrix(terrainBoard, terrainRows, terrainCols);
        if ( readMatixReturn == SUCCESS) {
            printMatrix(terrainBoard, terrainRows, terrainCols); // printing matix (delete)
        } else if (readMatixReturn == INVALID_DATA) {
            puts("Invalid data");
            return EXIT_FAILURE;
        } else {
            puts("Insuficient data");
            return EXIT_FAILURE;
        }
       
        free(terrainBoard); // free continious matix memory
    } else {
        puts("Invalid data");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}


int readMatrix(char* terrainBoard, const int rows, const int cols) {
    for(int count = 0; count < rows * cols; count++) {
       if ( scanf(" %c", &terrainBoard[count]) != 1) return INSUFICIENT_DATA;
       if (terrainBoard[count] != 'X' && terrainBoard[count] != '-') return INVALID_DATA;
    }
    terrainBoard[rows * cols] = '\0';
    return SUCCESS;
}

void printMatrix(char* terrainBoard, const int rows, const int cols) {
     for(int count = 0; count < rows * cols; count++) {
        if (count % cols == 0 & count != 0) printf("\n");
        printf("%c", terrainBoard[count]);
    }
    printf("\n");
}

