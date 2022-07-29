// Solved 2022-07-29
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (100.00%)

func bestHand(ranks []int, suits []byte) string {
	if suits[0] == suits[1] &&
		suits[1] == suits[2] &&
		suits[2] == suits[3] &&
		suits[3] == suits[4] {
		return "Flush"
	}
	buckets := make([]int, 14)
	maxSame := 0
	for _, rank := range ranks {
		buckets[rank]++
		if buckets[rank] > maxSame {
			maxSame = buckets[rank]
		}
	}
	if maxSame >= 3 {
		return "Three of a Kind"
	} else if maxSame == 2 {
		return "Pair"
	} else {
		return "High Card"
	}
}
