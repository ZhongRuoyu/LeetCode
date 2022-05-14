// Solved 2022-05-14
// Runtime: 2 ms (82.52%)
// Memory Usage: 3 MB (91.26%)

func cellsInRange(s string) []string {
	colStart := s[0]
	rowStart := s[1]
	colEnd := s[3]
	rowEnd := s[4]
	result := make([]string, 0, (colEnd-colStart+1)*(rowEnd-rowStart+1))
	for col := colStart; col <= colEnd; col++ {
		for row := rowStart; row <= rowEnd; row++ {
			result = append(result, string(col)+string(row))
		}
	}
	return result
}
