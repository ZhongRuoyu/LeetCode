// Solved 2021-04-17 08:51
// Runtime: 52 ms (87.35%)
// Memory Usage: 39.8 MB (99.80%)

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> ans(T.size());
        stack<int> st;
        for (int i = T.size() - 1; i != -1; --i) {
            while (!st.empty() && T[i] >= T[st.top()]) {
                st.pop();
            }
            ans[i] = st.empty() ? 0 : st.top() - i;
            st.push(i);
        }
        return ans;
    }
};

/* 

Another approach starting from the beginning:

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> ans(T.size());
        stack<int> st;
        for (int i = 0; i != T.size(); ++i) {
            while (!st.empty() && T[i] > T[st.top()]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

*/
