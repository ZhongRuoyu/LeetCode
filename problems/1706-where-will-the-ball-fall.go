// Solved 2022-08-13
// Runtime: 26 ms (82.32%)
// Memory Usage: 6.5 MB (97.24%)

func findBall(grid [][]int) []int {
	height := len(grid)
	width := len(grid[0])
	result := make([]int, width)
	for i := 0; i < width; i++ {
		col := i
		for row := 0; row < height; row++ {
			newCol := col + grid[row][col]
			if newCol < 0 || newCol >= width || grid[row][col] != grid[row][newCol] {
				col = -1
				break
			}
			col = newCol
		}
		result[i] = col
	}
	return result
}
