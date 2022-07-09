// Solved 2022-07-09
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (100.00%)

func digitSum(s string, k int) string {
	for len(s) > k {
		strSum := ""
		for i := 0; i < len(s); i += k {
			sum := 0
			limit := i + k
			if limit > len(s) {
				limit = len(s)
			}
			for j := i; j < limit; j++ {
				sum += int(s[j] - '0')
			}
			strSum += strconv.Itoa(sum)
		}
		s = strSum
	}
	return s
}
