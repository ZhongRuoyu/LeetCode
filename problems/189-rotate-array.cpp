// Solved 2021-12-08
// Runtime: 24 ms (89.56%)
// Memory Usage: 24.9 MB (77.98%)

class Solution {
   public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k %= n;
        int count = gcd(n, k);
        for (int i = 0; i < count; ++i) {
            int current = i;
            int temp = nums[current];
            do {
                current = (current + k) % n;
                swap(temp, nums[current]);
            } while (current != i);
        }
    }
};

/*

An alternative approach:

class Solution {
   public:
    void rotate(vector<int> &nums, int k) {
        k %= nums.size();
        reverse(begin(nums), end(nums));
        reverse(begin(nums), begin(nums) + k);
        reverse(begin(nums) + k, end(nums));
    }
};

*/
