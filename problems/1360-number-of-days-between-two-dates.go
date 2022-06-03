// Solved 2022-06-03
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.9 MB (63.16%)

func daysBetweenDates(date1 string, date2 string) int {
	time1, _ := time.Parse("2006-01-02", date1)
	time2, _ := time.Parse("2006-01-02", date2)
	if time1.After(time2) {
		time1, time2 = time2, time1
	}
	return int(time2.Sub(time1).Hours()) / 24
}
