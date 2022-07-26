// Solved 2022-07-26
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (88.89%)

func fillCups(amount []int) int {
	max := 0
	sum := 0
	for _, number := range amount {
		if number > max {
			max = number
		}
		sum += number
	}
	result := (sum + 1) / 2
	if max > result {
		result = max
	}
	return result
}
