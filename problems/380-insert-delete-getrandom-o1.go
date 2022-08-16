// Solved 2022-08-16
// Runtime: 205 ms (86.67%)
// Memory Usage: 49.1 MB (85.24%)

type RandomizedSet struct {
	data   []int
	lookup map[int]int
	rand   *rand.Rand
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		data:   make([]int, 0),
		lookup: make(map[int]int),
		rand:   rand.New(rand.NewSource(time.Now().UnixNano())),
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	_, present := this.lookup[val]
	if present {
		return false
	}
	this.lookup[val] = len(this.data)
	this.data = append(this.data, val)
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	index, present := this.lookup[val]
	if !present {
		return false
	}
	this.data[index] = this.data[len(this.data)-1]
	this.lookup[this.data[index]] = index
	this.data = this.data[:len(this.data)-1]
	delete(this.lookup, val)
	return true
}

func (this *RandomizedSet) GetRandom() int {
	return this.data[this.rand.Intn(len(this.data))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
