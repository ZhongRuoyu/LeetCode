// Solved 2022-07-27
// Runtime: 5 ms (100.00%)
// Memory Usage: 2.1 MB (100.00%)

func numberOfPairs(nums []int) []int {
	counts := make([]int, 101)
	for _, num := range nums {
		counts[num]++
	}
	pairCount := 0
	leftoverCount := 0
	for _, count := range counts {
		pairCount += count / 2
		leftoverCount += count % 2
	}
	return []int{pairCount, leftoverCount}
}
