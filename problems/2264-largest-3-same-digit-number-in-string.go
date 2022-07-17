// Solved 2022-07-17
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (78.26%)

func largestGoodInteger(num string) string {
	var largestDigit byte = 0
	for i := 2; i < len(num); i++ {
		if num[i-2] == num[i-1] && num[i-1] == num[i] {
			if num[i] > largestDigit {
				largestDigit = num[i]
			}
		}
	}
	if largestDigit == 0 {
		return ""
	}
	return string([]byte{largestDigit, largestDigit, largestDigit})
}
