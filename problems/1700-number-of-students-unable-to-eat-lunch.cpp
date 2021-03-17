// Solved 2021-03-17 14:20
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.7 MB (94.90%)

class Solution {
   public:
    int countStudents(vector<int> &students, vector<int> &sandwiches) {
        vector<int> count{0, 0};
        int taken;
        for (auto &i : students) ++count[i];
        for (taken = 0; taken != sandwiches.size() && count[sandwiches[taken]] > 0; ++taken) {
            --count[sandwiches[taken]];
        }
        return sandwiches.size() - taken;
    }
};

/* 

Using simulation:

class Solution {
   public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int resetCount = 0;
        while (true) {
            if (students.empty()) return 0;
            if (resetCount == students.size()) return students.size();
            if (students[0] == sandwiches[0]) {
                resetCount = 0;
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
            } else {
                ++resetCount;
                students.push_back(students[0]);
                students.erase(students.begin());
            }
        }
    }
};

*/
