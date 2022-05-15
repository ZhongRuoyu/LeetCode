// Solved 2022-05-15
// Runtime: 3 ms (94.39%)
// Memory Usage: 3.7 MB (67.29%)

func findKDistantIndices(nums []int, key int, k int) []int {
	result := make([]int, 0)
	next := 0
	for i, num := range nums {
		if num == key {
			j := i - k
			if next > j {
				j = next
			}
			end := i + k
			if end >= len(nums) {
				end = len(nums) - 1
			}
			for ; j <= end; j++ {
				result = append(result, j)
			}
			next = j
		}
	}
	return result
}
