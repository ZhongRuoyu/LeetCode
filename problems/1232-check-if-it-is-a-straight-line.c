// Solved 2021-01-04 07:26
// Runtime: 4 ms (100.00%)
// Memory Usage: 6.5 MB (69.77%)

bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
    if (coordinatesSize <= 2) return true;
    for (int i = 2; i < coordinatesSize; i++) {
        // area of triangle (*2)
        if (coordinates[0][0] * (coordinates[1][1] - coordinates[i][1]) +
                coordinates[1][0] * (coordinates[i][1] - coordinates[0][1]) +
                coordinates[i][0] * (coordinates[0][1] - coordinates[1][1]) !=
            0) {
            return false;
        }
    }
    return true;
}
