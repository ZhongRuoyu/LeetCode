// Solved 2022-05-12
// Runtime: 2 ms (75.86%)
// Memory Usage: 3.6 MB (59.77%)

func prefixCount(words []string, pref string) int {
	count := 0
	for _, word := range words {
		if len(word) >= len(pref) && word[:len(pref)] == pref {
			count++
		}
	}
	return count
}
