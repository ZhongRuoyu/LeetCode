// Solved 2022-02-12
// Runtime: 541 ms (88.94%)
// Memory Usage: 112.5 MB (94.72%)

// Union-Find data structure with path compression and weighted union
class UnionFind {
   private:
    const size_t n_;
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
    }
};

class Solution {
   public:
    bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
        UnionFind uf(n);
        for (auto &edge : edges) {
            uf.Union(edge[0], edge[1]);
        }
        return uf.Find(start) == uf.Find(end);
    }
};
