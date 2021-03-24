// Solved 2021-03-24 09:08
// Runtime: 4 ms (77.20%)
// Memory Usage: 6.6 MB (91.58%)

class Solution {
   public:
    string removeOuterParentheses(string S) {
        stack<int> st;
        for (int i = 0; i != S.size(); ++i) {
            if (S[i] == '(') {
                st.push(i);
            } else if (S[i] == ')') {
                // std::string.erase is inefficient.
                // We are not getting the original copy anyway.
                if (st.size() == 1) S[st.top()] = S[i] = '-';
                st.pop();
            }
        }
        string res;
        for (auto &ch : S) {
            if (ch != '-') res.push_back(ch);
        }
        return res;
    }
};
