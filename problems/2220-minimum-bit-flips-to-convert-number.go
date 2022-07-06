// Solved 2022-07-06
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (82.86%)

func minBitFlips(start int, goal int) int {
	return countSetBits(start ^ goal)
}

func countSetBits(x int) int {
	count := 0
	for x != 0 {
		count++
		x &= x - 1
	}
	return count
}
