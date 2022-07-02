// Solved 2022-07-02
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.4 MB (91.22%)

func largestNumber(nums []int) string {
	strs := make([]string, len(nums))
	for i, num := range nums {
		strs[i] = strconv.Itoa(num)
	}
	sort.Slice(strs, func(i, j int) bool {
		return strs[i]+strs[j] > strs[j]+strs[i]
	})
	if len(strs) > 0 && strs[0] == "0" {
		return "0"
	}
	return strings.Join(strs, "")
}
