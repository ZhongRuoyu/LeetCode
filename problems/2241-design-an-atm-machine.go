// Solved 2022-07-08
// Runtime: 285 ms (66.67%)
// Memory Usage: 8.4 MB (82.22%)

const banknoteValuesCount = 5

var banknoteValues = []int{20, 50, 100, 200, 500}

type ATM struct {
	banknotes []int // 20, 50, 100, 200, 500 dollars
}

func Constructor() ATM {
	return ATM{
		banknotes: make([]int, banknoteValuesCount),
	}
}

func (this *ATM) Deposit(banknotesCount []int) {
	for i := 0; i < banknoteValuesCount; i++ {
		this.banknotes[i] += banknotesCount[i]
	}
}

func (this *ATM) Withdraw(amount int) []int {
	result := make([]int, banknoteValuesCount)
	for i := banknoteValuesCount - 1; i >= 0; i-- {
		result[i] = amount / banknoteValues[i]
		if result[i] > this.banknotes[i] {
			result[i] = this.banknotes[i]
		}
		amount -= result[i] * banknoteValues[i]
	}

	if amount != 0 {
		return []int{-1}
	}
	for i := 0; i < banknoteValuesCount; i++ {
		this.banknotes[i] -= result[i]
	}

	return result
}

/**
 * Your ATM object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Deposit(banknotesCount);
 * param_2 := obj.Withdraw(amount);
 */
