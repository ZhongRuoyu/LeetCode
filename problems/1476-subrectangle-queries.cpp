// Solved 2021-04-29 20:25
// Runtime: 28 ms (99.20%)
// Memory Usage: 18.3 MB (84.26%)

class SubrectangleQueries {
   public:
    SubrectangleQueries(vector<vector<int>> &rectangle) {
        this->rectangle.swap(rectangle);
    }

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        history.push_back({row1, col1, row2, col2, newValue});
    }

    int getValue(int row, int col) {
        for (int i = history.size() - 1; i != -1; --i) {
            if (history[i][0] <= row && row <= history[i][2] &&
                history[i][1] <= col && col <= history[i][3]) {
                return history[i][4];
            }
        }
        return rectangle[row][col];
    }

   private:
    vector<vector<int>> rectangle;
    vector<vector<int>> history;  // tracks update history
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
