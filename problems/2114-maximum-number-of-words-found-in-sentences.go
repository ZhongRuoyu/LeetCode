// Solved 2022-05-04
// Runtime: 2 ms (88.50%)
// Memory Usage: 3.5 MB (86.00%)

func mostWordsFound(sentences []string) int {
	result := 0
	for _, sentence := range sentences {
		wordCount := 1
		for _, ch := range sentence {
			if ch == ' ' {
				wordCount++
			}
		}
		if wordCount > result {
			result = wordCount
		}
	}
	return result
}
