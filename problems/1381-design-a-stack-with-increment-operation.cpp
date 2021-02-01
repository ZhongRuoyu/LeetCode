// Solved 2021-02-01 10:12
// Runtime: 32 ms (92.95%)
// Memory Usage: 20.9 MB (97.96%)

class CustomStack {
   public:
    CustomStack(int maxSize) {
        if (maxSize <= 0) return;
        this->maxSize = maxSize;
    }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) return -1;
        int top = stack.back();
        stack.pop_back();
        return top;
    }

    void increment(int k, int val) {
        for (auto it = stack.begin(); k > 0 && it != stack.end(); --k, ++it) {
            *it += val;
        }
    }

   private:
    vector<int> stack;
    int maxSize;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
