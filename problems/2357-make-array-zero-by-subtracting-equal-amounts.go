// Solved 2022-07-31
// Runtime: 3 ms (100.00%)
// Memory Usage: 2.2 MB (100.00%)

func minimumOperations(nums []int) int {
	buckets := make(map[int]int)
	for _, num := range nums {
		if num > 0 {
			buckets[num]++
		}
	}
	return len(buckets)
}
