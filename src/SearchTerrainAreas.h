typedef long long terrainSize_t;

typedef struct SafeArea {
    terrainSize_t row;
    terrainSize_t col;
    terrainSize_t size;
} safeArea_t;

void SearchingForShelterInTheFlood(char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols);
void searchTerrainAreas(char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols);
void cloneTerrain(char* terrain, char* terrainClone, terrainSize_t terrainRows, terrainSize_t terrainCols);
void searchTerrain(char* terrain, safeArea_t* newArea, terrainSize_t cellRow, terrainSize_t cellCol,
    terrainSize_t terrainRows, terrainSize_t terrainCols);
void replaceCell(char* terrain, terrainSize_t row, terrainSize_t col, terrainSize_t terrainRows,
    terrainSize_t terrainCols);
void replace(safeArea_t** safeAreaArr, char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols);
void printMatrix(char *terrainBoard, const terrainSize_t rows, const terrainSize_t cols);
