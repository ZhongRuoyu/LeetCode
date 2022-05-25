// Solved 2022-05-25
// Runtime: 3 ms (100.00%)
// Memory Usage: 3.7 MB (100.00%)

func maxCount(m int, n int, ops [][]int) int {
	row, col := m, n
	for _, op := range ops {
		if op[0] < row {
			row = op[0]
		}
		if op[1] < col {
			col = op[1]
		}
	}
	return row * col
}
