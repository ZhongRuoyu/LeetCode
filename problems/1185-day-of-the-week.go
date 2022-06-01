// Solved 2022-06-01
// Runtime: 0 ms (100.00%)
// Memory Usage: 1.8 MB (100.00%)

func dayOfTheWeek(day int, month int, year int) string {
	// Sakamoto's methods
	// https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Sakamoto's_methods
	daysOfTheWeek := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
	t := []int{0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}
	if month < 3 {
		year -= 1
	}
	return daysOfTheWeek[(year+year/4-year/100+year/400+t[month-1]+day)%7]
}
