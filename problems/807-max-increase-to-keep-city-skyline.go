func maxIncreaseKeepingSkyline(grid [][]int) int {
	rowMaxes := make([]int, len(grid))
	colMaxes := make([]int, len(grid))
	for i, row := range grid {
		for j, cell := range row {
			if cell > rowMaxes[i] {
				rowMaxes[i] = cell
			}
			if cell > colMaxes[j] {
				colMaxes[j] = cell
			}
		}
	}

	result := 0
	for i, row := range grid {
		for j, cell := range row {
			max := rowMaxes[i]
			if colMaxes[j] < max {
				max = colMaxes[j]
			}
			result += max - cell
		}
	}

	return result
}
