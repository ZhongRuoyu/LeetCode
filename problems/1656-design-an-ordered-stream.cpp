// Solved 2021-02-03 08:17
// Runtime: 88 ms (99.35%)
// Memory Usage: 83.7 MB (87.45%)

class OrderedStream {
   public:
    OrderedStream(int n) {
        stream = vector<string>(n, "");
    }

    vector<string> insert(int id, string value) {
        if (id < 1 || id > stream.size()) return {};
        vector<string> chunk;
        stream[id - 1] = value;
        while (ptr != stream.size() && !stream[ptr].empty()) {
            chunk.emplace_back(stream[ptr++]);
        }
        return chunk;
    }

   private:
    vector<string> stream;
    int ptr = 0;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(id,value);
 */
