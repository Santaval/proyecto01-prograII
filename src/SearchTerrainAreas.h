typedef long long terrainSize_t;

/**
 * @struct SafeArea
 * keeps one coordenate of every safe area and it's size
 */
typedef struct SafeArea {
    terrainSize_t row; /** row of the cell of one safe spot */
    terrainSize_t col; /** column of the cell of one safe spot */
    terrainSize_t size; /** size of the safe area */
} safeArea_t;

/**
 * @brief Calls the main functions of the program and shows the result.
 * 
 * @param terrain continuous matrix of chars that saves the initial terrain.
 * @param terrainRows rows of the matrix.
 * @param terrainCols columns of the matrix.
 * @param argc arguments amount to print matix in stdout or file
 */
void SearchingForShelterInTheFlood(char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols, int argc);

/**
 * @brief creates a copy of the original matrix, the copy is going to be 
 * modified later
 * @param terrain original matrix 
 * @param terrainClone copied matrix (values are going to be saved here)
 * @param terrainRows total of rows of both matrixes
 * @param terrainCols total of columns of both matrixes
 */
void cloneTerrain(char* terrain, char* terrainClone, terrainSize_t terrainRows, terrainSize_t terrainCols);

/**
 * @brief replaces the current '-' cell with a 'C' to remember that it's
 * already checked, then checks every cell arround the current one and
 * repeat the same procces
 * @param terrain copy of the original matrix that is going to be checked
 * @param newArea struct of the safe area that keeps the size of the area
 * @param cellRow row of the current cell
 * @param cellCol column of the current cell
 * @param terrainRows total of rows of the matrix
 * @param terrainCols total of columns of the matrix
 */
void searchTerrain(char* terrain, safeArea_t* newArea, terrainSize_t cellRow, terrainSize_t cellCol,
    terrainSize_t terrainRows, terrainSize_t terrainCols);

/**
 * @brief when the biggest safe area of the terrain is already known, every
 * '-' is replaced with a 'R'
 * @param terrain original matrix of the terrain
 * @param row row of the current cell
 * @param col column of the current cell
 * @param terrainRows total rows of the matrix
 * @param terrainCols total columns of the matrix
 */
void replaceCell(char* terrain, terrainSize_t row, terrainSize_t col, terrainSize_t terrainRows,
    terrainSize_t terrainCols);

/**
 * @brief analyzes the array of safe areas in order to finde the biggest(s) one(s)
 * 
 * @param safeAreaArr array of structs of every safe area in the terrain
 * @param terrain original matrix of the terrain
 * @param terrainRows total of rows of the matrix
 * @param terrainCols total of columns of the matrix
 * @return total amount of replaced areas
 */
terrainSize_t replace(safeArea_t** safeAreaArr, char* terrain, terrainSize_t terrainRows, terrainSize_t terrainCols);

/**
 * @brief prints the final result and delete the continuous matrix and the array
 * 
 * @param terrainBoard final matrix of the terrain
 * @param safeAreaArr array with all the safe areas
 * @param rows total of rows of the matrix
 * @param cols total of columns of the matrix
 * @param argc arguments amount to print matix in stdout or file
 * @param totalAreas total areas founded
 */
void printMatrix(char *terrainBoard, const terrainSize_t rows,
    const terrainSize_t cols, int argc, terrainSize_t totalAreas);
