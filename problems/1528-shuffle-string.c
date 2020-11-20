// Solved 2020-11-20 17:48
// Runtime: 4 ms (89.50%)
// Memory Usage: 6.2 MB (51.71%)

char* restoreString(char* s, int* indices, int indicesSize) {
    char* x = (char*)malloc(sizeof(char) * (indicesSize + 1));
    for (int i = 0; i < indicesSize; i++) {
        x[indices[i]] = s[i];
    }
    x[indicesSize] = '\0';
    return x;
}
