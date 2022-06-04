// Solved 2022-06-04
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.8 MB (100.00%)

func numWaterBottles(numBottles int, numExchange int) int {
	result := numBottles
	for numBottles >= numExchange {
		numEmptyBottles := numBottles % numExchange
		numBottles /= numExchange
		result += numBottles
		numBottles += numEmptyBottles
	}
	return result
}
