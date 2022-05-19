// Solved 2022-05-19
// Runtime: 46 ms (89.70%)
// Memory Usage: 7.6 MB (73.33%)

func findDisappearedNumbers(nums []int) []int {
	for _, num := range nums {
		var index int
		if num > 0 {
			index = num - 1
		} else {
			index = -num - 1
		}
		if nums[index] > 0 {
			nums[index] = -nums[index]
		}
	}
	result := make([]int, 0)
	for i, num := range nums {
		if num > 0 {
			result = append(result, i+1)
		}
	}
	return result
}
