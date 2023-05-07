#include <stdio.h>
#include <stdlib.h>
#include <SearchTerrainAreas.h>



void searchTerrainAreas (char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols) {

    char* terrainClone = (char*) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
    cloneTerrain(terrain, terrainClone, terrainRows, terrainCols);
    puts("Clone");
    printMatrix(terrainClone, terrainRows, terrainCols);

}

void cloneTerrain(char* terrain, char* terrainClone, terrainSize_t terrainRows, terrainSize_t terrainCols) {
    for (terrainSize_t index = 0; index < terrainRows * terrainCols; index++) {
        terrainClone[index] = terrain[index];
    }
    terrainClone[terrainRows * terrainCols] = '\0';
}


