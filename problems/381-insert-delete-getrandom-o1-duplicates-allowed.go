// Solved 2022-08-17
// Runtime: 254 ms (95.00%)
// Memory Usage: 49.7 MB (80.00%)

type RandomizedCollection struct {
	data   []int
	lookup map[int]map[int]struct{}
	rand   *rand.Rand
}

func Constructor() RandomizedCollection {
	return RandomizedCollection{
		data:   make([]int, 0),
		lookup: make(map[int]map[int]struct{}),
		rand:   rand.New(rand.NewSource(time.Now().UnixNano())),
	}
}

func (this *RandomizedCollection) Insert(val int) bool {
	indices, present := this.lookup[val]
	if indices == nil {
		indices = make(map[int]struct{})
	}
	indices[len(this.data)] = struct{}{}
	this.data = append(this.data, val)
	this.lookup[val] = indices
	return !present
}

func (this *RandomizedCollection) Remove(val int) bool {
	indices, present := this.lookup[val]
	if !present {
		return false
	}
	index := 0
	for i := range indices {
		index = i
		break
	}
	delete(this.lookup[val], index)
	this.data[index] = this.data[len(this.data)-1]
	this.lookup[this.data[index]][index] = struct{}{}
	delete(this.lookup[this.data[index]], len(this.data)-1)
	this.data = this.data[:len(this.data)-1]
	if len(this.lookup[val]) == 0 {
		delete(this.lookup, val)
	}
	return true
}

func (this *RandomizedCollection) GetRandom() int {
	return this.data[this.rand.Intn(len(this.data))]
}

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */
