// Solved 2021-12-17
// Runtime: 3 ms (77.90%)
// Memory Usage: 9.3 MB (95.98%)

class Solution {
   public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        return Search(matrix, target, 0,
                      matrix.size() * matrix.front().size() - 1);
    }

   private:
    bool Search(vector<vector<int>> &matrix, int target, size_t begin,
                size_t end) {
        size_t m = matrix.size();
        size_t n = matrix.front().size();
        size_t begin_i = begin / n;
        size_t begin_j = begin % n;
        size_t end_i = end / n;
        size_t end_j = end % n;
        if (begin > end || end == -1) {
            return false;
        }
        if (begin == end) {
            return matrix[begin_i][begin_j] == target;
        }
        size_t mid = begin + (end - begin) / 2;
        size_t mid_i = mid / n;
        size_t mid_j = mid % n;
        if (matrix[mid_i][mid_j] == target) {
            return true;
        } else if (matrix[mid_i][mid_j] > target) {
            return Search(matrix, target, begin, mid - 1);
        } else {
            return Search(matrix, target, mid + 1, end);
        }
    }
};
