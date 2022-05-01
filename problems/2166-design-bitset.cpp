// Solved 2022-05-01
// Runtime: 447 ms (84.87%)
// Memory Usage: 198.5 MB (29.62%)

class Bitset {
   private:
    vector<uint64_t> set;
    size_t size;
    size_t set_bit_count;
    bool flipped;

    void set_bit(int idx) {
        if (((set[idx / 64] >> (idx % 64)) & 1) == 0) {
            set[idx / 64] |= 1ULL << (idx % 64);
            ++set_bit_count;
        }
    }

    void clear_bit(int idx) {
        if (((set[idx / 64] >> (idx % 64)) & 1) == 1) {
            set[idx / 64] &= ~(1ULL << (idx % 64));
            --set_bit_count;
        }
    }

   public:
    Bitset(int size) {
        this->set = vector<uint64_t>((size + 63) / 64, 0);
        this->size = size;
        this->set_bit_count = 0;
        this->flipped = false;
    }

    void fix(int idx) {
        if (flipped) {
            clear_bit(idx);
        } else {
            set_bit(idx);
        }
    }

    void unfix(int idx) {
        if (flipped) {
            set_bit(idx);
        } else {
            clear_bit(idx);
        }
    }

    void flip() {
        flipped = !flipped;
    }

    bool all() {
        return flipped ? set_bit_count == 0 : set_bit_count == size;
    }

    bool one() {
        return flipped ? set_bit_count < size : set_bit_count > 0;
    }

    int count() {
        return flipped ? size - set_bit_count : set_bit_count;
    }

    string toString() {
        string result;
        for (size_t i = 0; i < size; ++i) {
            if (flipped) {
                result += "10"[(set[i / 64] >> (i % 64)) & 1];
            } else {
                result += "01"[(set[i / 64] >> (i % 64)) & 1];
            }
        }
        return result.substr(0, size);
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */
