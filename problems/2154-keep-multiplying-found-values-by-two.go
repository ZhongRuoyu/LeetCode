// Solved 2022-05-10
// Runtime: 3 ms (96.36%)
// Memory Usage: 2.4 MB (100.00%)

func findFinalValue(nums []int, original int) int {
	lookup := make([]bool, 1001)
	for _, num := range nums {
		lookup[num] = true
	}
	result := original
	for result <= 1000 && lookup[result] {
		result *= 2
	}
	return result
}
