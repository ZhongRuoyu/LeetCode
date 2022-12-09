// Solved 2022-12-09
// Runtime: 128 ms (94.91%)
// Memory Usage: 37.2 MB (98.95%)

// Union-Find data structure with path compression.
class UnionFind {
   public:
    explicit UnionFind(size_t n) : n_(n), sets_(n) {
        iota(this->sets_.begin(), this->sets_.end(), 0);
    }

    int Find(size_t x) {
        if (x == this->sets_[x]) {
            return x;
        }
        sets_[x] = Find(sets_[x]);
        return sets_[x];
    }

    void Union(size_t x, size_t y) {
        int root_p = Find(x);
        int root_q = Find(y);
        if (root_p == root_q) {
            return;
        }
        sets_[root_p] = root_q;
        --n_;
    }

    size_t Size() { return n_; }

   private:
    size_t n_;
    vector<int> sets_;
};

class Solution {
   public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        UnionFind uf(n);
        for (auto &connection : connections) {
            uf.Union(connection[0], connection[1]);
        }
        int size = uf.Size();
        if (size == 1) {
            return 0;
        }
        return size - 1;
    }
};
