// Solved 2022-06-02
// Runtime: 2 ms (57.69%)
// Memory Usage: 2 MB (57.69%)

func minCostToMoveChips(position []int) int {
	even, odd := 0, 0
	for _, pos := range position {
		if pos%2 == 0 {
			even++
		} else {
			odd++
		}
	}
	if even > odd {
		return odd
	} else {
		return even
	}
}
