// Solved 2022-04-16
// Runtime: 4 ms (93.51%)
// Memory Usage: 5.7 MB (96.64%)

class Solution {
   public:
    int countPrimeSetBits(int left, int right) {
        // in the magic number, the prime bits are set
        constexpr unsigned int magic =
            0b1000'1000'1000'1010'0010'1000'1010'1100;
        int count = 0;
        for (int i = left; i <= right; ++i) {
            count += (magic >> pop_count(i)) & 1;
        }
        return count;
    }

   private:
    int pop_count(unsigned int n) {
        int result = 0;
        while (n != 0) {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};
