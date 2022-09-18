// Solved 2022-09-18
// Runtime: 9 ms (74.19%)
// Memory Usage: 2.6 MB (100.00%)

impl Solution {
    pub fn all_paths_source_target(graph: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut paths = Vec::<Vec<i32>>::new();
        let mut path = Vec::<i32>::new();
        Self::dfs(&graph, &mut paths, &mut path, 0);
        paths
    }

    fn dfs(graph: &Vec<Vec<i32>>, paths: &mut Vec<Vec<i32>>, path: &mut Vec<i32>, curr: i32) {
        path.push(curr);
        if curr == (graph.len() - 1) as i32 {
            paths.push(path.clone());
        } else {
            for next in graph[curr as usize].iter() {
                Self::dfs(graph, paths, path, *next);
            }
        }
        path.pop();
    }
}
