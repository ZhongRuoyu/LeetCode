// Solved 2022-11-26
// Runtime: 0 ms (100.00%)
// Memory Usage: 2.2 MB (77.14%)

impl Solution {
    pub fn can_visit_all_rooms(rooms: Vec<Vec<i32>>) -> bool {
        let mut rooms = rooms;
        let mut visited = vec![false; rooms.len()];
        let mut to_visit = Vec::new();
        visited[0] = true;
        to_visit.append(&mut rooms[0]);
        while let Some(next) = to_visit.pop() {
            if !visited[next as usize] {
                visited[next as usize] = true;
                to_visit.append(&mut rooms[next as usize]);
            }
        }
        visited.iter().all(|t| *t)
    }
}
