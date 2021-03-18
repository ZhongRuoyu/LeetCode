// Solved 2021-03-18 08:01
// Runtime: 4 ms (89.92%)
// Memory Usage: 11 MB (99.80%)

class Solution {
   public:
    string reformatNumber(string number) {
        // remove all spaces and dashes
        for (auto it = number.begin(); it != number.end();) {
            if (*it == ' ' || *it == '-') {
                number.erase(it);
            } else {
                ++it;
            }
        }
        int i;
        // group the digits into blocks of length 3
        for (i = 0; i + 4 < number.size(); i += 4) {
            number.insert(number.begin() + i + 3, '-');
        }
        // group the final digits
        if (number.size() == i + 4) {
            number.insert(number.begin() + i + 2, '-');
        }
        return number;
    }
};

// It is much simpler to use regex!
