// Solved 2022-05-26
// Runtime: 32 ms (93.10%)
// Memory Usage: 6.5 MB (77.93%)

func maximumProduct(nums []int) int {
	max1, max2, max3 := math.MinInt, math.MinInt, math.MinInt
	min1, min2 := math.MaxInt, math.MaxInt
	for _, num := range nums {
		if num >= max1 {
			max3 = max2
			max2 = max1
			max1 = num
		} else if num >= max2 {
			max3 = max2
			max2 = num
		} else if num >= max3 {
			max3 = num
		}
		if num <= min1 {
			min2 = min1
			min1 = num
		} else if num <= min2 {
			min2 = num
		}
	}
	max := max1 * max2 * max3
	if t := min1 * min2 * max1; t > max {
		max = t
	}
	return max
}
