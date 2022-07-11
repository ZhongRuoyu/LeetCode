// Solved 2022-07-11
// Runtime: 8 ms (79.22%)
// Memory Usage: 3.8 MB (93.51%)

func intersection(nums [][]int) []int {
	counts := make([]int, 1001)
	for _, arr := range nums {
		for _, num := range arr {
			counts[num]++
		}
	}

	result := make([]int, 0)
	for num, count := range counts {
		if count == len(nums) {
			result = append(result, num)
		}
	}

	return result
}
