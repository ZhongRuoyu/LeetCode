// Solved 2022-08-15
// Runtime: 3 ms (98.60%)
// Memory Usage: 2.8 MB (100.00%)

func isMatch(s string, p string) bool {
	sPos := 0
	pPos := 0
	sNextPos := len(s)
	pStarPos := len(p)

	for sPos != len(s) {
		if pPos != len(p) && (p[pPos] == '?' || s[sPos] == p[pPos]) {
			sPos++
			pPos++
			continue
		}
		if pPos != len(p) && p[pPos] == '*' {
			pStarPos = pPos
			pPos++
			sNextPos = sPos + 1
			continue
		}
		if pStarPos != len(p) {
			pPos = pStarPos + 1
			sPos = sNextPos
			sNextPos++
			continue
		}
		return false
	}

	for pPos != len(p) && p[pPos] == '*' {
		pPos++
	}

	return pPos == len(p)
}
