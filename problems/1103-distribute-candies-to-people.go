// Solved 2022-05-30
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (79.17%)

func distributeCandies(candies int, num_people int) []int {
	result := make([]int, num_people)
	for i := 0; candies > 0; i++ {
		c := i + 1
		if candies < c {
			c = candies
		}
		result[i%num_people] += c
		candies -= c
	}
	return result
}
