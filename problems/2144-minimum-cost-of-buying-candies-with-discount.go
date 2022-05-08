// Solved 2022-05-08
// Runtime: 2 ms (81.82%)
// Memory Usage: 2.5 MB (77.27%)

func minimumCost(cost []int) int {
	result := 0
	sort.Slice(cost, func(i, j int) bool { return cost[i] > cost[j] })
	for len(cost) >= 3 {
		result += cost[0] + cost[1]
		cost = cost[3:]
	}
	for _, c := range cost {
		result += c
	}
	return result
}
