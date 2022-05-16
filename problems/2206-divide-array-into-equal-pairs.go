// Solved 2022-05-16
// Runtime: 7 ms (92.54%)
// Memory Usage: 4.1 MB (93.53%)

func divideArray(nums []int) bool {
	count := make([]int, 501)
	for _, num := range nums {
		count[num]++
	}
	for _, c := range count {
		if c%2 != 0 {
			return false
		}
	}
	return true
}
