// Solved 2022-05-23
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (67.35%)

func convertToBase7(num int) string {
	if num < 0 {
		return "-" + convertToBase7(-num)
	}
	if num < 7 {
		return strconv.Itoa(num)
	}
	return convertToBase7(num/7) + strconv.Itoa(num%7)
}
