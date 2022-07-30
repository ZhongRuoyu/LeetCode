// Solved 2022-07-30
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (94.16%)

func repeatedCharacter(s string) byte {
	buckets := make([]byte, 26)
	for i := 0; i < len(s); i++ {
		if buckets[s[i]-'a'] > 0 {
			return s[i]
		}
		buckets[s[i]-'a']++
	}
	return 0
}
