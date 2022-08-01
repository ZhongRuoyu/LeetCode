// Solved 2022-08-01
// Runtime: 7 ms (68.18%)
// Memory Usage: 2.4 MB (68.18%)

func countTriples(n int) int {
	isSquare := make(map[int]bool)
	for i := 1; i <= n; i++ {
		isSquare[i*i] = true
	}

	count := 0
	for i := 1; i <= n; i++ {
		for j := i; i*i+j*j <= n*n; j++ {
			if isSquare[i*i+j*j] {
				count += 2
			}
		}
	}

	return count
}
