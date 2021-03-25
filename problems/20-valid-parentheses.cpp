// Solved 2021-03-25 08:03
// Runtime: 0 ms (100.00%)
// Memory Usage: 6.2 MB (88.60%)

class Solution {
   public:
    bool isValid(string s) {
        stack<char> expected;
        for (auto &ch : s) {
            if (ch == ')' || ch == ']' || ch == '}') {
                if (expected.empty() || ch != expected.top()) return false;
                expected.pop();
            } else {
                // assuming s consists of parentheses only '()[]{}'
                expected.push(getClosingBracket(ch));
            }
        }
        return expected.empty();
    }

   private:
    constexpr char getClosingBracket(char ch) {
        // assuming ch is one of the opening brackets '(' '[' '{'
        return (ch == '(')   ? ')'
               : (ch == '[') ? ']'
                             : '}';
    }
};
