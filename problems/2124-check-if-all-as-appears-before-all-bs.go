// Solved 2022-05-06
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (100.00%)

func checkString(s string) bool {
	i := 0
	for i < len(s) && s[i] == 'a' {
		i++
	}
	for i < len(s) && s[i] == 'b' {
		i++
	}
	return i == len(s)
}
