// Solved 2022-07-22
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (91.02%)

func greatestLetter(s string) string {
	letters := make([]struct {
		lower bool
		upper bool
	}, 26)
	for _, letter := range s {
		if unicode.IsUpper(letter) {
			letters[letter-'A'].upper = true
		} else {
			letters[unicode.ToUpper(letter)-'A'].lower = true
		}
	}
	for i := len(letters) - 1; i >= 0; i-- {
		if letters[i].upper && letters[i].lower {
			return string(byte('A' + i))
		}
	}
	return ""
}
