// Solved 2022-05-29
// Runtime: 27 ms (86.84%)
// Memory Usage: 6.9 MB (67.11%)

func addToArrayForm(num []int, k int) []int {
	i := len(num) - 1
	carry := 0
	for ; k > 0 || carry > 0; k /= 10 {
		if i >= 0 {
			x := num[i] + k%10 + carry
			num[i] = x % 10
			carry = x / 10
			i--
		} else {
			x := k%10 + carry
			num = insert(num, 0, x%10)
			carry = x / 10
		}
	}
	return num
}

func insert(slice []int, index int, value int) []int {
	slice = append(slice[:index+1], slice[index:]...)
	slice[index] = value
	return slice
}
