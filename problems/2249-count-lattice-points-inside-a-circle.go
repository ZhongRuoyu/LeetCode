// Solved 2022-08-08
// Runtime: 109 ms (77.27%)
// Memory Usage: 2.3 MB (77.27%)

func countLatticePoints(circles [][]int) int {
	count := 0
	for x := 0; x <= 200; x++ {
		for y := 0; y <= 200; y++ {
			for _, circle := range circles {
				if (x-circle[0])*(x-circle[0])+
					(y-circle[1])*(y-circle[1]) <=
					circle[2]*circle[2] {
					count++
					break
				}
			}
		}
	}
	return count
}
