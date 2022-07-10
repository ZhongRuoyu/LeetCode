// Solved 2022-07-10
// Runtime: 165 ms (84.21%)
// Memory Usage: 9.8 MB (78.95%)

func minimumRounds(tasks []int) int {
	difficulties := make(map[int]int)
	for _, task := range tasks {
		difficulties[task]++
	}

	rounds := 0
	for _, count := range difficulties {
		if count == 1 {
			return -1
		}
		rounds += (count + 2) / 3
	}

	return rounds
}
