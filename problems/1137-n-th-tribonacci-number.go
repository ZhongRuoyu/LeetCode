// Solved 2022-05-31
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (84.86%)

func tribonacci(n int) int {
	if n <= 0 {
		return 0
	}
	if n <= 2 {
		return 1
	}
	t0, t1, t2 := 0, 1, 1
	for i := 2; i < n; i++ {
		t0, t1, t2 = t1, t2, t0+t1+t2
	}
	return t2
}
