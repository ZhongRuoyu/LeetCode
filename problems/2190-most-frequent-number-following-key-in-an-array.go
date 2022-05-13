// Solved 2022-05-13
// Runtime: 7 ms (77.03%)
// Memory Usage: 4 MB (100.00%)

func mostFrequent(nums []int, key int) int {
	count := make([]int, 1001)
	result := nums[0]
	for i := 0; i < len(nums)-1; i++ {
		if nums[i] == key {
			count[nums[i+1]]++
			if count[nums[i+1]] > count[result] {
				result = nums[i+1]
			}
		}
	}
	return result
}
