// Solved 2022-02-21
// Runtime: 0 ms (100.00%)
// Memory Usage: 25.4 MB (84.41%)

class Solution {
   public:
    vector<int> twoOutOfThree(vector<int> &nums1, vector<int> &nums2,
                              vector<int> &nums3) {
        array<int, 101> counts{};
        array<int, 101> present{};
        vector<reference_wrapper<vector<int>>> nums_list = {nums1, nums2,
                                                            nums3};
        for (size_t i = 0; i < nums_list.size(); ++i) {
            auto nums = nums_list[i].get();
            for (int num : nums) {
                present[num] = i + 1;
            }
            for (int num = 1; num <= 100; ++num) {
                if (present[num] == i + 1) ++counts[num];
            }
        }
        vector<int> result;
        for (int num = 1; num <= 100; ++num) {
            if (counts[num] >= 2) {
                result.push_back(num);
            }
        }
        return result;
    }
};
