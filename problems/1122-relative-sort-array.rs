// Solved 2023-01-28
// Runtime: 0 ms (100.00%)
// Memory Usage: 2 MB (93.75%)

impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        let lookup = arr2
            .iter()
            .enumerate()
            .map(|(i, num)| (num, i as i32))
            .collect::<std::collections::BTreeMap<_, _>>();
        let mut arr1 = arr1;
        arr1.sort_unstable_by_key(|num| lookup.get(num).map_or(*num, |order| i32::MIN + order));
        arr1
    }
}
