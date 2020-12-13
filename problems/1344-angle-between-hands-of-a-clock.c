// Solved 2020-12-13 13:55
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.4 MB (84.00%)

double angleClock(int hour, int minutes) {
    double h = hour * 30.0 + minutes * 0.5, m = minutes * 6.0,
           ans = (h > m) ? h - m : m - h;
    return (ans <= 180) ? ans : 360 - ans;
}
