// Solved 2023-01-30
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.1 MB (64.29%)

impl Solution {
    pub fn distance_between_bus_stops(distance: Vec<i32>, start: i32, destination: i32) -> i32 {
        let mut start = start as usize;
        let mut destination = destination as usize;
        if start > destination {
            let tmp = start;
            start = destination;
            destination = tmp;
        }
        std::cmp::min(
            distance.iter().skip(start).take(destination - start).sum(),
            distance
                .iter()
                .take(start)
                .chain(distance.iter().skip(destination))
                .sum(),
        )
    }
}
