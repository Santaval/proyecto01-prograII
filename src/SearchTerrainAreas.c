/* Copyright (C) 2023 Marcelo Picado, Aaron Santana - All Rights Reserved
 * You may use, distribute and modify this code under the
 * terms of the XYZ license, which unfortunately won't be
 * written for another century.
 */
#include <stdio.h>
#include <stdlib.h>
#include "SearchTerrainAreas.h"
#include <string.h>

void SearchingForShelterInTheFlood(char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols, int argc, char* filename) {
       char* terrainClone = malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
    safeArea_t** safeAreaArr = malloc(sizeof(safeArea_t*) * (terrainRows * terrainCols));
    for (terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
        safeAreaArr[index] = NULL; //initialize the matrix
    }
    terrainSize_t pushedAreas = 0;
    cloneTerrain(terrain, terrainClone, terrainRows, terrainCols);
    for (terrainSize_t rowCounter = 0; rowCounter < terrainRows; rowCounter++) {
        for (terrainSize_t colCounter = 0; colCounter < terrainCols; colCounter++) {
            if (terrainClone[terrainCols * rowCounter + colCounter] == '-') {
                //starts searching for safe areas
                safeArea_t* newArea = malloc(sizeof(safeArea_t));
                //keeps the coordenates of one cell of the safe area
                newArea -> row = rowCounter;
                newArea -> col = colCounter;
                newArea -> size = 0; //keeps the size of the safe area
                searchTerrain(terrainClone, newArea, rowCounter, colCounter, terrainRows, terrainCols);
                safeAreaArr[pushedAreas] = newArea; //saves the safe area in a array of structs
                pushedAreas++; //goes for the next safe area
            }
        }
    }
    terrainSize_t totalAreas = replace(safeAreaArr, terrain, terrainRows, terrainCols);
    printMatrix(terrain, terrainRows, terrainCols, argc, totalAreas, filename);
    for(int i = 0; i < terrainRows * terrainCols; i++){
        free(safeAreaArr[i]); //frees every slot of the array of structs
    }
    free(safeAreaArr); //frees the array itself
    free(terrainClone); //frees the cloned matrix
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
        //increase the size of the safe area and start a recursive search in 4 directions (up, down, right, left)
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
        //start a recursive search in 4 directions (up, down, right, left)
        if (row + 1 < terrainRows) replaceCell(terrain, row + 1, col, terrainRows, terrainCols);
        if (row - 1 >= 0) replaceCell(terrain, row - 1, col, terrainRows, terrainCols);
        if (col + 1 < terrainCols) replaceCell(terrain, row, col + 1, terrainRows, terrainCols);
        if (col - 1 >= 0) replaceCell(terrain, row, col - 1, terrainRows, terrainCols);
    }
}

terrainSize_t replace(safeArea_t** safeAreaArr, char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    terrainSize_t arrLength = terrainRows * terrainCols; //quantitie of elements of the array
    terrainSize_t biggest = 0; //keeps the size of the biggest safe area
    int areas = 0; //areas that have been succesfully replaced
    for (terrainSize_t i = 0; i < arrLength; i++) {
        if (safeAreaArr[i] != NULL) {
            if (safeAreaArr[i]->size > biggest) {
                biggest = safeAreaArr[i]->size; //keeps the size of the biggest area
            }
        }
    }
    //analyzes the entire array, replazing every safe area with a refugee every time the area is the 
    //same size as the biggest area
    for (int i = 0; i < arrLength; i++) { 
        if (safeAreaArr[i] != NULL && safeAreaArr[i]->size == biggest) {
            areas++;
            replaceCell(terrain, safeAreaArr[i]->row, safeAreaArr[i]->col, terrainRows, terrainCols);
        }
    }
    return areas;
}

void printMatrix(char *terrainBoard, const terrainSize_t rows,
        const terrainSize_t cols, int argc, terrainSize_t totalAreas, char* filename) {
if (argc == 1) {
        // Imprimir en la salida estándar (stdout)
        printf("%lld\n", totalAreas);
        for (int rowCount = 0; rowCount < rows; rowCount++) {
            for (int colCount = 0; colCount < cols; colCount++) {
                printf("%c", terrainBoard[cols * rowCount + colCount]);
            }
            printf("\n");
        }
    } else if (argc == 2 || argc == 3) {
      
        sprintf(filename, "%s-out.txt", filename);
        FILE* txtDoc = fopen(filename, "w");
        if (txtDoc == NULL) {
            printf("Error al abrir el archivo.\n");
            return;
        }
        fprintf(txtDoc,"%lld\n", totalAreas);
        for (int rowCount = 0; rowCount < rows; rowCount++) {
            for (int colCount = 0; colCount < cols; colCount++) {
                fprintf(txtDoc, "%c", terrainBoard[cols * rowCount + colCount]);
            }
            fprintf(txtDoc, "\n");
        }

        fclose(txtDoc);

        printf("Resultado guardado en el archivo \"%s\".\n", filename);

    }

}

