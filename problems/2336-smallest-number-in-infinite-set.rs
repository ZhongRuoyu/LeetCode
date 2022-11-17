// Solved 2022-11-17
// Runtime: 19 ms (100.00%)
// Memory Usage: 2.4 MB (75.00%)

struct SmallestInfiniteSet {
    added_back: std::collections::BTreeSet<i32>,
    next: i32,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl SmallestInfiniteSet {
    fn new() -> Self {
        Self {
            added_back: std::collections::BTreeSet::new(),
            next: 1,
        }
    }

    fn pop_smallest(&mut self) -> i32 {
        if self.added_back.is_empty() {
            let result = self.next;
            self.next += 1;
            result
        } else {
            let result = *self.added_back.iter().next().unwrap_or(&0);
            self.added_back.remove(&result);
            result
        }
    }

    fn add_back(&mut self, num: i32) {
        if num < self.next {
            self.added_back.insert(num);
        }
    }
}

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * let obj = SmallestInfiniteSet::new();
 * let ret_1: i32 = obj.pop_smallest();
 * obj.add_back(num);
 */
