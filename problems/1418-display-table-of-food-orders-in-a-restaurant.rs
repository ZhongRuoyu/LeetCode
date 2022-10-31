// Solved 2022-10-31
// Runtime: 74 ms (92.86%)
// Memory Usage: 17.1 MB (100.00%)

impl Solution {
    pub fn display_table(orders: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let mut food_items = std::collections::BTreeSet::new();
        let mut tables = std::collections::BTreeMap::new();

        for order in orders {
            let table_number = order[1].clone();
            let food_item = order[2].clone();
            food_items.insert(food_item.clone());
            *tables
                .entry(table_number.parse::<i32>().unwrap_or_default())
                .or_insert_with(|| std::collections::BTreeMap::<_, i32>::new())
                .entry(food_item)
                .or_default() += 1;
        }

        let mut display_table = Vec::new();

        let mut header = Vec::new();
        header.push(String::from("Table"));
        for food_item in food_items.iter() {
            header.push(food_item.clone());
        }
        display_table.push(header);

        for (table_number, table) in tables {
            let mut row = Vec::new();
            row.push(table_number.to_string());
            for food_item in food_items.iter() {
                let food_item_ordered = table.get(food_item).unwrap_or(&0);
                row.push(food_item_ordered.to_string());
            }
            display_table.push(row)
        }

        display_table
    }
}

/*

A "one-liner" that's (of course) less readable:

impl Solution {
    pub fn display_table(orders: Vec<Vec<String>>) -> Vec<Vec<String>> {
        (|(food_items, tables): (
            std::collections::BTreeSet<_>,
            std::collections::BTreeMap<i32, std::collections::BTreeMap<_, _>>,
        )| {
            Some(
                Some(String::from("Table"))
                    .into_iter()
                    .chain(food_items.clone().into_iter())
                    .collect(),
            )
            .into_iter()
            .chain(tables.iter().map(|(table_number, table)| {
                Some(table_number.to_string())
                    .into_iter()
                    .chain(
                        food_items
                            .iter()
                            .map(|food_item| table.get(food_item).unwrap_or(&0).to_string()),
                    )
                    .collect()
            }))
            .collect()
        })(orders.into_iter().fold(
            (
                std::collections::BTreeSet::new(),
                std::collections::BTreeMap::new(),
            ),
            |(mut food_items, mut tables), order| {
                food_items.insert(order[2].clone());
                tables
                    .entry(order[1].parse::<i32>().unwrap_or_default())
                    .or_default()
                    .entry(order[2].clone())
                    .and_modify(|count| *count += 1)
                    .or_insert(1);
                (food_items, tables)
            },
        ))
    }
}

*/
