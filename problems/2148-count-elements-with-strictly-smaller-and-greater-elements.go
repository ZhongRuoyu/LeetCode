// Solved 2022-05-09
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.4 MB (100.00%)

func countElements(nums []int) int {
	min, minCount := math.MaxInt, 0
	max, maxCount := math.MinInt, 0
	for _, num := range nums {
		if num < min {
			min = num
			minCount = 0
		}
		if num > max {
			max = num
			maxCount = 0
		}
		if num == min {
			minCount++
		}
		if num == max {
			maxCount++
		}
	}
	if min == max {
		return len(nums) - minCount
	} else {
		return len(nums) - minCount - maxCount
	}
}

// First day of work... Let's go!
