// Solved 2022-05-21
// Runtime: 40 ms (72.23%)
// Memory Usage: 6.5 MB (97.29%)

func findMaxConsecutiveOnes(nums []int) int {
	ones := 0
	max := 0
	for _, num := range nums {
		if num == 0 {
			ones = 0
		} else {
			ones++
		}
		if ones > max {
			max = ones
		}
	}
	return max
}
