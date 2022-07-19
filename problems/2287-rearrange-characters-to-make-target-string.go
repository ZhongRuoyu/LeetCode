// Solved 2022-07-19
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (80.98%)

func rearrangeCharacters(s string, target string) int {
	sMap := makeMap(s)
	targetMap := makeMap(target)

	result := math.MaxInt
	for char, charCount := range targetMap {
		sCharCount := sMap[char]
		if result > sCharCount/charCount {
			result = sCharCount / charCount
		}
	}

	return result
}

func makeMap(str string) map[byte]int {
	result := make(map[byte]int)
	for i := range str {
		result[str[i]]++
	}
	return result
}
