// Solved 2022-05-17
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (88.34%)

func isHappy(n int) bool {
	for n != 1 && n != 4 {
		n = getNext(n)
	}
	return n == 1
}

func getNext(n int) int {
	sum := 0
	for ; n != 0; n /= 10 {
		x := n % 10
		sum += x * x
	}
	return sum
}
