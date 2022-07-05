// Solved 2022-07-05
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (92.52%)

func minimumSum(num int) int {
	s := []byte(strconv.Itoa(num))
	sort.Slice(s, func(i, j int) bool { return s[i] < s[j] })
	return int((s[0]-'0'+s[1]-'0')*10 + s[2] - '0' + s[3] - '0')
}
