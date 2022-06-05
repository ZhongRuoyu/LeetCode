// Solved 2022-06-05
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.8 MB (85.00%)

func subsetXORSum(nums []int) int {
	sum := 0
	for _, num := range nums {
		sum |= num
	}
	return sum << (len(nums) - 1)
}
