// Solved 2021-01-03 10:45
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.5 MB (87.61%)

bool isUgly(int num) {
    for (int i = 3; i < 6 && num; i++)
        while (num % i == 0) num /= i;
    return (num == 1 || num == 2);
}
