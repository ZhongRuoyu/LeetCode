// Solved 2020-11-26 10:56
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (100.00%)

int dayOfYear(char* date) {
    int a[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334},
        y, m, d;
    sscanf(date, "%d-%d-%d", &y, &m, &d);
    d += a[m - 1];
    if ((m > 2) && !(y % 4) && ((y % 100) || !(y % 400))) d++;
    return d;
}
