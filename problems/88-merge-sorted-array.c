// Solved 2021-01-06 10:25
// Runtime: 4 ms (86.25%)
// Memory Usage: 6.1 MB (90.69%)

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    --m, --n;
    while (n >= 0) {
        nums1[--nums1Size] = (m >= 0 && nums1[m] > nums2[n]) ? nums1[m--] : nums2[n--];
    }
};
