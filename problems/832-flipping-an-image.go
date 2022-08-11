// Solved 2022-08-11
// Runtime: 3 ms (80.53%)
// Memory Usage: 2.8 MB (100.00%)

func flipAndInvertImage(image [][]int) [][]int {
	n := len(image)
	for _, row := range image {
		for i := 0; i <= n-1-i; i++ {
			row[i], row[n-1-i] = 1-row[n-1-i], 1-row[i]
		}
	}
	return image
}
