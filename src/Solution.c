#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Solution.h>
#include <SearchTerrainAreas.h>

enum EXIT_CODES
{
    ERR,
    SUCCESS,
    INSUFICIENT_DATA,
    INVALID_DATA,
    FILE_NOT_FOUND
};

int main(int argc, char *argv[])
{

    /// Creating int variables to keep row, cols values and array for cantinious matrix in dynamic memory
    terrainSize_t terrainRows = 0; // matrix rows
    terrainSize_t terrainCols = 0; // matix cols
    char *terrainBoard;  // pointer to char array in dynamic memory

    if (argc > 1 && !strcmp(argv[1], "-b"))
    {
        FILE *binDoc;
        binDoc = fopen(argv[2], "rb");

        if (binDoc == NULL)
        {
            puts("Binary file not found");
            return EXIT_FAILURE;
        }

        if (fread(&terrainRows, sizeof(terrainBoard), 1, binDoc) == 1 && fread(&terrainCols, sizeof(terrainSize_t), 1, binDoc) == 1)
        {   
            terrainBoard = (char *) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
            int readBinaryMatixReturn = readBinaryMatrix(terrainBoard, terrainRows, terrainCols, binDoc);
             if (readBinaryMatixReturn == SUCCESS)
            {
                printMatrix(terrainBoard, terrainRows, terrainCols); // printing matix (delete)
            }
            else if (readBinaryMatixReturn == INVALID_DATA)
            {
                puts("Invalid data");
                return EXIT_FAILURE;
            }
            else
            {
                puts("Insuficient data");
                return EXIT_FAILURE;
            }

            free(terrainBoard); // free continious matix memory

        }
        else
        {
            puts("Invalidad Data");
            return EXIT_FAILURE;
        }
    }
    else
    {
        /// reading matrix dimmensions and validate them
        if (scanf("%llu %llu", &terrainRows, &terrainCols) == 2)
        {
            /// assign dynamic memory spae to keep continious matix
            terrainBoard = (char *) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
            const int readMatixReturn = readMatrix(terrainBoard, terrainRows, terrainCols);
            if (readMatixReturn == SUCCESS)
            {   
                searchTerrainAreas(terrainBoard, terrainRows, terrainCols);
                printMatrix(terrainBoard, terrainRows, terrainCols); // printing matix (delete)
                free(terrainBoard);
            }
            else if (readMatixReturn == INVALID_DATA)
            {
                puts("Invalid data");
                return EXIT_FAILURE;
            }
            else
            {
                puts("Insuficient data");
                return EXIT_FAILURE;
            }

            free(terrainBoard); // free continious matix memory
        }
        else
        {
            puts("Invalid data");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}

int readMatrix(char *terrainBoard, const terrainSize_t rows, const terrainSize_t cols)
{
    for (terrainSize_t count = 0; count < rows * cols; count++)
    {
        if (scanf(" %c", &terrainBoard[count]) != 1)
            return INSUFICIENT_DATA;
        if (terrainBoard[count] != 'X' && terrainBoard[count] != '-')
            return INVALID_DATA;
    }
    terrainBoard[rows * cols] = '\0';
    return SUCCESS;
}

int readBinaryMatrix (char* terrainBoard, const terrainSize_t rows, const terrainSize_t cols, FILE* binDoc) {
     for (int count = 0; count < rows * cols; count++)
    {
        if (fread(&terrainBoard[count], sizeof(char), 1, binDoc) != 1)
            return INSUFICIENT_DATA;
        if (terrainBoard[count] != 'X' && terrainBoard[count] != '-')
            return INVALID_DATA;
    }
    terrainBoard[rows * cols] = '\0';
    return SUCCESS;
}

void printMatrix(char *terrainBoard, const terrainSize_t rows, const terrainSize_t cols)
{
    for (terrainSize_t count = 0; count < rows * cols; count++)
    {
        if (count % cols == 0 & count != 0)
            printf("\n");
        printf("%c", terrainBoard[count]);
    }
    printf("\n");
}
