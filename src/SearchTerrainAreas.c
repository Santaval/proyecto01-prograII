#include <stdio.h>
#include <stdlib.h>
#include <SearchTerrainAreas.h>

void printMatrixs(char *terrainBoard, const terrainSize_t rows, const terrainSize_t cols)
{
    for (terrainSize_t count = 0; count < rows * cols; count++)
    {
        if (count % cols == 0 & count != 0)
            printf("\n");
        printf("%c", terrainBoard[count]);
    }
    printf("\n");
}


safeArea_t**  searchTerrainAreas (char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    char* terrainClone = (char*) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
    safeArea_t** safeAreaArr = (safeArea_t**) malloc(sizeof(safeArea_t**) * terrainRows * terrainCols);
    for(terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
        safeAreaArr[index] = NULL;    
    }
    terrainSize_t pushedAreas = 0;
    cloneTerrain(terrain, terrainClone, terrainRows, terrainCols);
    for (terrainSize_t rowCounter = 0; rowCounter < terrainRows; rowCounter++) {
        for (terrainSize_t colCounter = 0; colCounter < terrainCols; colCounter++) {
            if(terrainClone[terrainCols * rowCounter + colCounter] == '-') {
                safeArea_t* newArea = (safeArea_t*) malloc(sizeof(safeArea_t*));
                newArea -> row = rowCounter;
                newArea -> col = colCounter;
                newArea -> size = 0;
                searchTerrain(terrainClone, newArea, rowCounter, colCounter, terrainRows, terrainCols);
                safeAreaArr[pushedAreas] = newArea;
                 printf("%llu\n", newArea -> size);
                 //printMatrixs(terrainClone, terrainRows, terrainCols);
                pushedAreas++;
            }
        }
    }

    // for(terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
    //     if(safeAreaArr[index] != NULL) {
    //         printf("%llu\n", safeAreaArr[index] -> size);
    //         //free(safeAreaArr[index]);
    //     }
    // }
    return safeAreaArr;

    //free(safeAreaArr);
    //free(terrainClone);

}

void cloneTerrain(char* terrain, char* terrainClone, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    for (terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
        terrainClone[index] = terrain[index];
    }
    terrainClone[terrainRows * terrainCols] = '\0';
}

void searchTerrain(char* terrain, safeArea_t* newArea, terrainSize_t cellRow, terrainSize_t cellCol, terrainSize_t terrainRows, terrainSize_t terrainCols ) {
    if(terrain[terrainCols * cellRow + cellCol] == '-') {
        terrain[terrainCols * cellRow + cellCol] = 'C';
        newArea -> size+= 1;

        if(cellRow + 1 < terrainRows) searchTerrain(terrain, newArea, cellRow + 1, cellCol, terrainRows, terrainCols);
        if(cellRow - 1 >= 0) searchTerrain(terrain, newArea, cellRow - 1, cellCol, terrainRows, terrainCols);
        if(cellCol + 1 < terrainCols) searchTerrain(terrain, newArea, cellRow, cellCol + 1, terrainRows, terrainCols);
        if(cellCol - 1 >= 0) searchTerrain(terrain, newArea, cellRow, cellCol - 1, terrainRows, terrainCols);
    }
}



