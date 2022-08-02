// Solved 2022-08-02
// Runtime: 71 ms (97.81%)
// Memory Usage: 8.1 MB (92.90%)

type MyHashSet struct {
	data []int64
}

func Constructor() MyHashSet {
	return MyHashSet{
		data: make([]int64, 1e6/64+1),
	}
}

func (this *MyHashSet) Add(key int) {
	bucket := key >> 6
	bit := key & 0x3f
	this.data[bucket] |= 1 << bit
}

func (this *MyHashSet) Remove(key int) {
	bucket := key >> 6
	bit := key & 0x3f
	this.data[bucket] &= ^(1 << bit)
}

func (this *MyHashSet) Contains(key int) bool {
	bucket := key >> 6
	bit := key & 0x3f
	return this.data[bucket]&(1<<bit) != 0
}

/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
