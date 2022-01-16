// Solved 2022-01-16
// Runtime: 40 ms (71.21%)
// Memory Usage: 18 MB (69.63%)

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        if (k < 1 || t < 0) {
            return false;
        }

        long long bucket_size = t + 1LL;
        unordered_map<long long, long long> map;

        for (size_t i = 0; i != nums.size(); ++i) {
            long long remapped =
                (long long)nums[i] - numeric_limits<int>::min();
            long long bucket = remapped / bucket_size;
            if (map.count(bucket) != 0 ||
                (map.count(bucket - 1) != 0 &&
                 remapped - map[bucket - 1] <= t) ||
                (map.count(bucket + 1) != 0 &&
                 map[bucket + 1] - remapped <= t)) {
                return true;
            }
            if (map.size() >= k) {
                long long last_bucket =
                    ((long long)nums[i - k] - numeric_limits<int>::min()) /
                    bucket_size;
                map.erase(last_bucket);
            }
            map[bucket] = remapped;
        }
        return false;
    }
};
