// Solved 2022-05-28
// Runtime: 39 ms (83.16%)
// Memory Usage: 6.6 MB (94.74%)

func largestPerimeter(nums []int) int {
	sort.Slice(nums, func(i, j int) bool { return nums[i] < nums[j] })
	for i := len(nums) - 3; i >= 0; i-- {
		if nums[i]+nums[i+1] > nums[i+2] {
			return nums[i] + nums[i+1] + nums[i+2]
		}
	}
	return 0
}
