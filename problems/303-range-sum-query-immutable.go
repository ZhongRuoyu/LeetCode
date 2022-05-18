// Solved 2022-05-18
// Runtime: 25 ms (91.43%)
// Memory Usage: 8.2 MB (94.76%)

type NumArray struct {
	lookup []int
}

func Constructor(nums []int) NumArray {
	lookup := make([]int, len(nums))
	sum := 0
	for i := range lookup {
		sum += nums[i]
		lookup[i] = sum
	}
	return NumArray{lookup: lookup}
}

func (this *NumArray) SumRange(left int, right int) int {
	if left == 0 {
		return this.lookup[right]
	} else {
		return this.lookup[right] - this.lookup[left-1]
	}
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * param_1 := obj.SumRange(left,right);
 */
