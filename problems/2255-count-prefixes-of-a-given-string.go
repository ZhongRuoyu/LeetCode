// Solved 2022-07-12
// Runtime: 0 ms (100.00%)
// Memory Usage: 3.6 MB (86.00%)

func countPrefixes(words []string, s string) int {
	count := 0
wordsLoop:
	for _, word := range words {
		if len(word) > len(s) {
			continue
		}
		for i := 0; i < len(word); i++ {
			if word[i] != s[i] {
				continue wordsLoop
			}
		}
		count++
	}
	return count
}
