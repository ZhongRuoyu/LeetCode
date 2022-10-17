// Solved 2022-10-17
// Runtime: 7 ms (90.00%)
// Memory Usage: 2.3 MB (78.89%)

impl Solution {
    pub fn merge_similar_items(items1: Vec<Vec<i32>>, items2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut items = std::collections::BTreeMap::new();
        [items1, items2].iter().for_each(|item_set| {
            item_set
                .iter()
                .for_each(|item| *items.entry(item[0]).or_default() += item[1])
        });
        <Vec<_> as std::iter::FromIterator<_>>::from_iter(
            items.into_iter().map(|item| vec![item.0, item.1]),
        )
    }
}
