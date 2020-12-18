// Solved 2020-12-18 11:11
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.6 MB (68.42%)

bool isBoomerang(int** points, int pointsSize, int* pointsColSize) {
    // area of triangle (*2)
    return (points[0][0] * (points[1][1] - points[2][1]) +
                points[1][0] * (points[2][1] - points[0][1]) +
                points[2][0] * (points[0][1] - points[1][1]) !=
            0);
}
