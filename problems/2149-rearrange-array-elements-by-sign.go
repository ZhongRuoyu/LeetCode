// Solved 2022-08-12
// Runtime: 222 ms (94.81%)
// Memory Usage: 11.2 MB (98.70%)

func rearrangeArray(nums []int) []int {
	result := make([]int, len(nums))
	nextPositive, nextNegative := 0, 1
	for _, num := range nums {
		if num > 0 {
			result[nextPositive] = num
			nextPositive += 2
		} else {
			result[nextNegative] = num
			nextNegative += 2
		}
	}
	return result
}
