// Solved 2021-04-22 08:11
// Runtime: 8 ms (88.79%)
// Memory Usage: 11.8 MB (84.95%)

class Solution {
   public:
    int evalRPN(vector<string> &tokens) {
        unordered_map<string, function<int(int, int)>> lookup{
            {"+", [](int x, int y) { return x + y; }},
            {"-", [](int x, int y) { return x - y; }},
            {"*", [](int x, int y) { return x * y; }},
            {"/", [](int x, int y) { return x / y; }}};
        stack<int> s;
        for (auto &token : tokens) {
            if (lookup.count(token)) {
                int y = s.top();
                s.pop();
                int x = s.top();
                s.pop();
                s.push(lookup[token](x, y));
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
