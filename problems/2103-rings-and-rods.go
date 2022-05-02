// Solved 2022-05-02
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (96.10%)

func countPoints(rings string) int {
	rods := make([]byte, 10)
	for i := 0; i < len(rings); i += 2 {
		switch rings[i] {
		case 'R':
			rods[rings[i+1]-'0'] |= 0b001
		case 'G':
			rods[rings[i+1]-'0'] |= 0b010
		case 'B':
			rods[rings[i+1]-'0'] |= 0b100
		}
	}
	count := 0
	for _, val := range rods {
		if val == 0b111 {
			count++
		}
	}
	return count
}
