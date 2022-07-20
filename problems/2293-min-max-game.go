// Solved 2022-07-20
// Runtime: 6 ms (62.63%)
// Memory Usage: 3.5 MB (63.64%)

func minMaxGame(nums []int) int {
	for len(nums) > 1 {
		newNums := make([]int, len(nums)/2)
		for i := range newNums {
			if i%2 == 0 {
				if nums[2*i] < nums[2*i+1] {
					newNums[i] = nums[2*i]
				} else {
					newNums[i] = nums[2*i+1]
				}
			} else {
				if nums[2*i] > nums[2*i+1] {
					newNums[i] = nums[2*i]
				} else {
					newNums[i] = nums[2*i+1]
				}
			}
		}
		nums = newNums
	}
	return nums[0]
}
