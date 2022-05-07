// Solved 2022-05-07
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (100.00%)

func divideString(s string, k int, fill byte) []string {
	result := make([]string, 0)
	for len(s) >= k {
		result = append(result, s[:k])
		s = s[k:]
	}
	if len(s) > 0 {
		last := make([]byte, k)
		for i := range last {
			if i < len(s) {
				last[i] = s[i]
			} else {
				last[i] = fill
			}
		}
		result = append(result, string(last))
	}
	return result
}
