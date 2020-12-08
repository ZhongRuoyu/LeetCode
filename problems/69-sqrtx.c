// Solved 2020-12-08 11:25
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (98.54%)

double Sqrt(int x) {
    if (x == 0) return 0;
    double x1 = x, x0;
    do {
        x0 = x1;
        x1 = (x1 + x / x1) * 0.5;
        // Newton's Method
    } while (fabs(x1 - x0) > 0.5);
    return x1;
}

int mySqrt(int x) {
    return (int)Sqrt(x);
}
