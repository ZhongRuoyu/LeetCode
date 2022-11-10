// Solved 2022-11-10
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.4 MB (33.33%)

impl Solution {
    pub fn mem_leak(memory1: i32, memory2: i32) -> Vec<i32> {
        let mut memory1 = memory1;
        let mut memory2 = memory2;
        let diff = (memory1 - memory2).abs();

        // only consume from the larger memory
        let steps = ((2.0 * diff as f64 + 0.25).sqrt() - 0.5).floor();
        if memory1 >= memory2 {
            memory1 -= (steps * (steps + 1.0) / 2.0) as i32;
        } else {
            memory2 -= (steps * (steps + 1.0) / 2.0) as i32;
        }

        // make memory1 >= memory2
        let swapped = if memory1 < memory2 {
            let temp = memory1;
            memory1 = memory2;
            memory2 = temp;
            true
        } else {
            false
        };

        // get last memory allocations
        let last1 = ((4.0 * memory1 as f64 + steps * steps).sqrt() - 1.0).floor() as i32;
        let last2 =
            ((4.0 * memory2 as f64 + (steps + 1.0) * (steps + 1.0)).sqrt() - 1.0).floor() as i32;

        // check parity
        let start = steps + 1.0;
        let last1 = if start as i32 % 2 == last1 % 2 {
            last1
        } else {
            last1 - 1
        };
        let last2 = if (start as i32 + 1) % 2 == last2 % 2 {
            last2
        } else {
            last2 - 1
        };

        let crash_time = std::cmp::max(last1, last2) + 1;
        memory1 -= ((last1 as f64 + start) * (last1 as f64 - start + 2.0) / 4.0) as i32;
        memory2 -= ((last2 as f64 + start + 1.0) * (last2 as f64 - start + 1.0) / 4.0) as i32;
        if swapped {
            let temp = memory1;
            memory1 = memory2;
            memory2 = temp;
        }
        vec![crash_time, memory1, memory2]
    }
}
