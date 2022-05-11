// Solved 2022-05-11
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.8 MB (84.06%)

func countOperations(num1 int, num2 int) int {
	count := 0
	for num1 > 0 && num2 > 0 {
		if num1 >= num2 {
			num1 -= num2
		} else {
			num2 -= num1
		}
		count++
	}
	return count
}
