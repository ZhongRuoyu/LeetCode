// Solved 2023-01-23
// Runtime: 8 ms (87.88%)
// Memory Usage: 6.6 MB (93.94%)

struct KthLargest {
  k: usize,
  heap: std::collections::BinaryHeap<std::cmp::Reverse<i32>>,
}

/**
* `&self` means the method takes an immutable reference.
* If you need a mutable reference, change it to `&mut self` instead.
*/
impl KthLargest {
  fn new(k: i32, nums: Vec<i32>) -> Self {
      let k = k as usize;
      let mut heap = std::collections::BinaryHeap::with_capacity(k + 1);
      for num in nums {
          heap.push(std::cmp::Reverse(num));
          if heap.len() > k {
              heap.pop();
          }
      }
      return Self { k, heap };
  }

  fn add(&mut self, val: i32) -> i32 {
      self.heap.push(std::cmp::Reverse(val));
      if self.heap.len() > self.k {
          self.heap.pop();
      }
      self.heap.peek().map(|num| num.0).unwrap_or_default()
  }
}

/**
* Your KthLargest object will be instantiated and called as such:
* let obj = KthLargest::new(k, nums);
* let ret_1: i32 = obj.add(val);
*/
