// Solved 2022-07-23
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (91.50%)

func countAsterisks(s string) int {
	count := 0
	inBetween := false
	for _, letter := range s {
		if letter == '|' {
			inBetween = !inBetween
		} else if letter == '*' {
			if !inBetween {
				count++
			}
		}
	}
	return count
}
