/* Copyright (C) 2023 Marcelo Picado, Aaron Santana - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 */
#include <stdio.h>
#include <stdlib.h>
#include "SearchTerrainAreas.h"



void SearchingForShelterInTheFlood(char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols ) {
    safeArea_t** safeAreaArr = malloc(sizeof(safeArea_t**) * (terrainRows * terrainCols));
    searchTerrainAreas(terrain, terrainRows, terrainCols);
    printMatrix(terrain, terrainRows, terrainCols);
}



void searchTerrainAreas(char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    char* terrainClone = malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
    safeArea_t** safeAreaArr = malloc(sizeof(safeArea_t*) * (terrainRows * terrainCols));
    for (terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
        safeAreaArr[index] = NULL;
    }
    terrainSize_t pushedAreas = 0;
    cloneTerrain(terrain, terrainClone, terrainRows, terrainCols);
    for (terrainSize_t rowCounter = 0; rowCounter < terrainRows; rowCounter++) {
        for (terrainSize_t colCounter = 0; colCounter < terrainCols; colCounter++) {
            if (terrainClone[terrainCols * rowCounter + colCounter] == '-') {
                safeArea_t* newArea = malloc(sizeof(safeArea_t));

                newArea -> row = rowCounter;
                newArea -> col = colCounter;
                newArea -> size = 0;

                searchTerrain(terrainClone, newArea, rowCounter, colCounter, terrainRows, terrainCols);
                safeAreaArr[pushedAreas] = newArea;
                pushedAreas++;
            }
        }
    }

    replace(safeAreaArr, terrain, terrainRows, terrainCols);

    // free(safeAreaArr);
    // free(terrainClone);
}

void cloneTerrain(char* terrain, char* terrainClone, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    for (terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
        terrainClone[index] = terrain[index];
    }
    terrainClone[terrainRows * terrainCols] = '\0';
}

void searchTerrain(char* terrain, safeArea_t* newArea, terrainSize_t cellRow, terrainSize_t cellCol,
        terrainSize_t terrainRows, terrainSize_t terrainCols) {
    if (terrain[terrainCols * cellRow + cellCol] == '-') {
        terrain[terrainCols * cellRow + cellCol] = 'C';
        newArea -> size+= 1;

        if (cellRow + 1 < terrainRows) searchTerrain(terrain, newArea, cellRow + 1, cellCol, terrainRows, terrainCols);
        if (cellRow - 1 >= 0) searchTerrain(terrain, newArea, cellRow - 1, cellCol, terrainRows, terrainCols);
        if (cellCol + 1 < terrainCols) searchTerrain(terrain, newArea, cellRow, cellCol + 1, terrainRows, terrainCols);
        if (cellCol - 1 >= 0) searchTerrain(terrain, newArea, cellRow, cellCol - 1, terrainRows, terrainCols);
    }
}

void replaceCell(char* terrain, terrainSize_t row, terrainSize_t col, terrainSize_t terrainRows,
        terrainSize_t terrainCols) {
     if (terrain[terrainCols * row + col] == '-') {
        terrain[terrainCols * row + col] = 'R';
        if (row + 1 < terrainRows) replaceCell(terrain, row + 1, col, terrainRows, terrainCols);
        if (row - 1 >= 0) replaceCell(terrain, row - 1, col, terrainRows, terrainCols);
        if (col + 1 < terrainCols) replaceCell(terrain, row, col + 1, terrainRows, terrainCols);
        if (col - 1 >= 0) replaceCell(terrain, row, col - 1, terrainRows, terrainCols);
    }
}

void replace(safeArea_t** safeAreaArr, char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    terrainSize_t arrLength = terrainRows * terrainCols;
    terrainSize_t biggest = 0;
    int areas = 0;
    for (terrainSize_t i = 0; i < arrLength; i++) {
        if (safeAreaArr[i] != NULL) {
            if (safeAreaArr[i]->size > biggest) {
                biggest = safeAreaArr[i]->size;
            }
        }
    }

    for (int i = 0; i < arrLength; i++) {
        if (safeAreaArr[i] != NULL && safeAreaArr[i]->size == biggest) {
            areas++;
            replaceCell(terrain, safeAreaArr[i]->row, safeAreaArr[i]->col, terrainRows, terrainCols);
        }
    }
    printf("%d\n",areas);
}


void printMatrix(char *terrainBoard, const terrainSize_t rows, const terrainSize_t cols) {
    for (terrainSize_t count = 0; count < rows * cols; count++) {
        if (count % cols == 0 && count != 0)
            printf("\n");
        printf("%c", terrainBoard[count]);
    }
    printf("\n");
}

