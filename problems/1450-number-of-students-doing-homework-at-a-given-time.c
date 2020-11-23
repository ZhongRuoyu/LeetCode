// Solved 2020-11-23 12:40
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.9 MB (83.33%)

int busyStudent(int* startTime, int startTimeSize, int* endTime, int endTimeSize, int queryTime) {
    int c = 0;
    for (int i = 0; i < startTimeSize; i++) {
        if ((startTime[i] <= queryTime) && (queryTime <= endTime[i])) c++;
    }
    return c;
}
