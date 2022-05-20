// Solved 2022-05-20
// Runtime: 30 ms (82.47%)
// Memory Usage: 6.2 MB (74.23%)

func findContentChildren(g []int, s []int) int {
	sort.Slice(g, func(i, j int) bool { return g[i] < g[j] })
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	gIndex, sIndex := 0, 0
	for gIndex < len(g) && sIndex < len(s) {
		if s[sIndex] >= g[gIndex] {
			gIndex++
		}
		sIndex++
	}
	return gIndex
}
