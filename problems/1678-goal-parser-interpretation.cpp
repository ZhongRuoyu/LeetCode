// Solved 2021-03-12 13:14
// Runtime: 0 ms (100.00%)
// Memory Usage: 5.8 MB (99.86%)

class Solution {
   public:
    string interpret(string command) {
        string res;
        int pos = 0;
        while (pos < command.size()) {
            if (command.substr(pos, 4) == "(al)") {
                res.append("al");
                pos += 4;
            } else if (command.substr(pos, 2) == "()") {
                res.push_back('o');
                pos += 2;
            } else {
                res.push_back('G');
                ++pos;
            }
        }
        return res;
    }
};
