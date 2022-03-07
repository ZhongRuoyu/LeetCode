// Solved 2022-03-07
// Runtime: 38 ms (77.29%)
// Memory Usage: 12.3 MB (84.55%)

class Solution {
   private:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        const size_t m = grid.size();
        const size_t n = grid.front().size();
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] != '0') {
            dfs(grid, i - 1, j);
        }
        if (i + 1 < m && grid[i + 1][j] != '0') {
            dfs(grid, i + 1, j);
        }
        if (j - 1 >= 0 && grid[i][j - 1] != '0') {
            dfs(grid, i, j - 1);
        }
        if (j + 1 < n && grid[i][j + 1] != '0') {
            dfs(grid, i, j + 1);
        }
    }

   public:
    int numIslands(vector<vector<char>> &grid) {
        const size_t m = grid.size();
        const size_t n = grid.front().size();
        int result = 0;
        for (size_t i = 0; i != m; ++i) {
            for (size_t j = 0; j != n; ++j) {
                if (grid[i][j] != '0') {
                    dfs(grid, i, j);
                    ++result;
                }
            }
        }
        return result;
    }
};

/*

Another solution using Union-Find:

const int X[]{0, -1};
const int Y[]{-1, 0};
const int DIRECTIONS = 2;

// Union-Find data structure with path compression and weighted union
class UnionFind {
    size_t n_;
    vector<size_t> sets;

   public:
    UnionFind(size_t n) : n_(n), sets(n) {
        iota(sets.begin(), sets.end(), 0);
    }

    size_t Find(size_t p) {
        return (sets[p] == p) ? p : (sets[p] = Find(sets[p]));
    }

    void Union(size_t p, size_t q) {
        size_t root_p = Find(p);
        size_t root_q = Find(q);
        if (root_p == root_q) {
            return;
        }
        sets[root_p] = root_q;
        --n_;
    }

    size_t size() {
        return n_;
    }
};

class Solution {
   public:
    int numIslands(vector<vector<char>> &grid) {
        const int m = grid.size();
        const int n = grid.front().size();
        UnionFind lookup(m * n + 1);  // one extra slot for water
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    lookup.Union(i * n + j, m * n);
                } else {
                    for (int k = 0; k < DIRECTIONS; ++k) {
                        int x = i + X[k];
                        int y = j + Y[k];
                        if (x < 0 || y < 0) {
                            continue;
                        }
                        if (grid[x][y] != '0') {
                            lookup.Union(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }
        return lookup.size() - 1;
    }
};

*/