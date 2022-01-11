// Solved 2022-01-11
// Runtime: 9 ms (78.35%)
// Memory Usage: 7.2 MB (63.24%)

// The Boyer-Moore algorithm (simplified)

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) {
            return 0;
        }
        if (n == 0) {
            return -1;
        }

        vector<int> char_jump = MakeCharJump(needle);

        int p_haystack = m - 1;
        int p_needle = m - 1;
        while (p_haystack < n) {
            if (p_needle < 0) {
                return p_haystack + 1;
            }
            if (haystack[p_haystack] == needle[p_needle]) {
                --p_haystack;
                --p_needle;
            } else {
                int char_jump_value = char_jump[haystack[p_haystack]];
                int jump = max(char_jump_value, m - p_needle);
                p_haystack += jump;
                p_needle = m - 1;
            }
        }

        return -1;
    }

   private:
    vector<int> MakeCharJump(string needle) {
        size_t m = needle.length();
        vector<int> char_jump(numeric_limits<char>::max(), m);
        for (size_t i = 0; i != m; ++i) {
            char_jump[needle[i]] = m - i - 1;
        }
        return char_jump;
    }
};

/*

A Boyer-Moore algorithm implementing matchJump as well. 'Tis a pity that
the MakeMatchJump is actually O(n^2)...

class Solution {
   public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if (m == 0) {
            return 0;
        }
        if (n == 0) {
            return -1;
        }

        vector<int> char_jump = MakeCharJump(needle);
        vector<int> match_jump = MakeMatchJump(needle);

        int p_haystack = m - 1;
        int p_needle = m - 1;
        while (p_haystack < n) {
            if (p_needle < 0) {
                return p_haystack + 1;
            }
            if (haystack[p_haystack] == needle[p_needle]) {
                --p_haystack;
                --p_needle;
            } else {
                int char_jump_value = char_jump[haystack[p_haystack]];
                int match_jump_value = match_jump[p_needle];
                int jump = max(char_jump_value, match_jump_value);
                p_haystack += jump;
                p_needle = m - 1;
            }
        }

        return -1;
    }

   private:
    vector<int> MakeCharJump(string needle) {
        size_t m = needle.length();
        vector<int> char_jump(numeric_limits<char>::max(), m);
        for (size_t i = 0; i != m; ++i) {
            char_jump[needle[i]] = m - i - 1;
        }
        return char_jump;
    }

    vector<int> MakeMatchJump(string needle) {
        size_t m = needle.length();
        vector<int> match_jump(m);

        for (size_t i = 0; i != m; ++i) {
            int matched = m - (i + 1);
            match_jump[i] = matched + m;
        }
        match_jump[m - 1] = 1;

        for (size_t i = 0; i != m; ++i) {
            for (size_t prefix_length = 1; (i + 1) + prefix_length <= m;
                 ++prefix_length) {
                if (needle.substr(0, prefix_length) ==
                    needle.substr(m - prefix_length, prefix_length)) {
                    int matched = m - (i + 1);
                    int slide = m - prefix_length;
                    match_jump[i] = matched + slide;
                }
            }
        }

        for (size_t i = 0; i + 1 < m; ++i) {
            for (size_t r = 0; r != i; ++r) {
                int matched = m - (i + 1);
                if (needle.substr(r + 1, matched) ==
                        needle.substr(i + 1, matched) &&
                    needle[r] != needle[i]) {
                    int earlier_occurrence_end = r + matched + 1;
                    int slide = m - earlier_occurrence_end;
                    match_jump[i] = matched + slide;
                }
            }
        }

        return match_jump;
    }
};

*/

/*

That's surprisingly fast, although this is cheating, obviously...

class Solution {
   public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

*/
