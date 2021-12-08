// Solved 2021-12-08
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.9 MB (90.13%)

class Solution {
   public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        --m;
        --n;
        for (size_t p = nums1.size(); n >= 0;) {
            nums1[--p] =
                (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
        }
    }
};
