// Solved 2022-05-22
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.8 MB (92.11%)

func constructRectangle(area int) []int {
	w := int(math.Floor(math.Sqrt(float64(area))))
	for area%w != 0 {
		w--
	}
	return []int{area / w, w}
}
