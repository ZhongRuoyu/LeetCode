// Solved 2020-11-28 10:51
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (85.71%)

int patternSize(char *pattern) {
    int l = strlen(pattern);
    char a[l + 1], *p;
    strncpy(a, pattern, l);
    a[l] = '\0';
    for (int i = 0; i < l; i++) {
        if (p = strchr(a + i + 1, a[i])) {
            *p = a[--l];
            a[l] = '\0';
            i--;
        }
    }
    return l;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findAndReplacePattern(char **words, int wordsSize, char *pattern, int *returnSize) {
    int i, j, k,
        l = strlen(pattern), ps = patternSize(pattern);
    char **r = (char **)malloc(sizeof(char *) * wordsSize);
    bool *matches = (bool *)malloc(sizeof(bool) * wordsSize);
    memset(matches, true, wordsSize);
    for (k = 0; k < wordsSize; k++) {
        if (patternSize(words[k]) != ps) {
            matches[k] = false;
        }
    }
    if (l != ps) {
        for (i = 0; i < l - 1; i++) {
            for (j = i + 1; j < l; j++) {
                // the loops i and j traverse the pattern
                if (pattern[i] != pattern[j]) continue;
                for (k = 0; k < wordsSize; k++) {
                    // the loop k traverses words
                    if (!matches[k]) continue;
                    if (words[k][i] != words[k][j]) {
                        matches[k] = false;
                    }
                }
            }
        }
    }
    *returnSize = 0;
    for (i = 0; i < wordsSize; i++) {
        if (matches[i]) r[(*returnSize)++] = words[i];
    }
    free(matches);
    return r;
}
