/* Copyright (C) 2023 Marcelo Picado, Aaron Santana - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Solution.h"
#include "SearchTerrainAreas.h"

/// exit codes

enum EXIT_CODES
{
    ERR,
    SUCCESS,
    INSUFICIENT_DATA,
    INVALID_DATA,
    FILE_NOT_FOUND
};


/// @brief main function
/// @param argc arguments amount
/// @param argv arguments array
/// @return bool (0 or 1) to represent the program the exit code
int main(int argc, char *argv[])
{

    /// Creating int variables to keep row, cols values and array for cantinious matrix in dynamic memory
    terrainSize_t terrainRows = 0;
    terrainSize_t terrainCols = 0; 

    // pointer to char array in dynamic memory
    char *terrainBoard;

    // validating if program receives a binary file oer not
    if (argc > 1 && !strcmp(argv[1], "-b"))
    {   
        // creating pointer and opening binary file
        FILE *binDoc;
        binDoc = fopen(argv[2], "rb");

        // validating file was founded
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
                SearchingForShelterInTheFlood(terrainBoard, terrainRows, terrainCols);     
            }
            else if (readBinaryMatixReturn == INVALID_DATA)
            {
                puts("invalid data");
                return EXIT_FAILURE;
            }
            else
            {
                puts("invalid data");
                return EXIT_FAILURE;
            }

            free(terrainBoard); // free continious matix memory

        }
        else
        {
            puts("invalidad Data");
            return EXIT_FAILURE;
        }
    }
    else
    {
        /// reading matrix dimmensions and validate them
        if (scanf("%lld %lld", &terrainRows, &terrainCols) == 2)
        {
            /// assign dynamic memory spae to keep continious matix
            terrainBoard = (char *) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
            const int readMatixReturn = readMatrix(terrainBoard, terrainRows, terrainCols);
            if (readMatixReturn == SUCCESS)
            {  
                SearchingForShelterInTheFlood(terrainBoard, terrainRows, terrainCols);       
            }
            else if (readMatixReturn == INVALID_DATA)
            {
                puts("invalid data");
                return EXIT_FAILURE;
            }
            else
            {
                puts("invalid data");
                return EXIT_FAILURE;
            }

            free(terrainBoard); // free continious matix memory
        }
        else
        {
            puts("invalid data");
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

