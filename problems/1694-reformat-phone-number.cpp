// Solved 2021-03-20 08:01
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (97.75%)

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
