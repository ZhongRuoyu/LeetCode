// Solved 2022-05-27
// Runtime: 12 ms (100.00%)
// Memory Usage: 5.6 MB (100.00%)

func hasGroupsSizeX(deck []int) bool {
	cards := make(map[int]int)
	for _, card := range deck {
		cards[card]++
	}
	result := -1
	for _, count := range cards {
		if result == -1 {
			result = count
		} else {
			result = gcd(result, count)
			if result == 1 {
				return false
			}
		}
	}
	return result > 1
}

func gcd(x, y int) int {
	if x == 0 {
		return y
	} else {
		return gcd(y%x, x)
	}
}
