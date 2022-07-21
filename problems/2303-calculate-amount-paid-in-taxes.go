// Solved 2022-07-21
// Runtime: 6 ms (83.67%)
// Memory Usage: 4.2 MB (88.78%)

func calculateTax(brackets [][]int, income int) float64 {
	tax := 0.0
	prev := 0
	for i := range brackets {
		tierMax := brackets[i][0]
		if tierMax > income {
			tierMax = income
		}
		amount := float64((tierMax-prev)*brackets[i][1]) / 100.0
		if amount > 0.0 {
			tax += amount
		}
		prev = brackets[i][0]
	}
	return tax
}
