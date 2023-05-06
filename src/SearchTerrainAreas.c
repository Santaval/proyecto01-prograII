#include <stdio.h>
#include <stdlib.h>
#include <SearchTerrainAreas.h>

void searchTerrainAreas (char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols) {

    char* terrainClone = (char*) malloc((sizeof(char) * (terrainCols * terrainRows)) + sizeof(char));
    cloneTerrain(terrain, terrainClone);

}

void cloneTerrain(char* terrain, char* terrainClone);