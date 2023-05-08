typedef long long terrainSize_t;


/**
 * Receives terrain dimensions and char pointer, in a loop read a char from stdin and insert it in the current index.
 * 
 * @param terrainBorad char array pointer for represent tearrin characters
 * @param terrainRow total rows of the terrain
 * @param terrainCol total columns of the terrain
 * 
*/
int readMatrix(char* terrainBoard, const terrainSize_t rows, const terrainSize_t cols);

/**
 * Receives terrain dimensions and char pointer, in a loop read a char from a binary file and insert it in the current index.
 * 
 * @param terrainBorad char array pointer for represent tearrin characters
 * @param terrainRow total rows of the terrain
 * @param terrainCol total columns of the terrain
 * 
*/
int readBinaryMatrix (char* terrainBoard, const terrainSize_t rows, const terrainSize_t cols, FILE* binDoc);

/**
 * Receives terrain dimensions and char pointer, in a loop ptint the current char in stdout .
 * 
 * @param terrainBorad char array pointer for represent tearrin characters
 * @param terrainRow total rows of the terrain
 * @param terrainCol total columns of the terrain
 * 
*/
void printMatrix(char* terrainBoard, const terrainSize_t rows, const terrainSize_t cols);