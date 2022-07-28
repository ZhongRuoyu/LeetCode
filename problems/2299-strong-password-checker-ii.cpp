// Solved 2022-07-28
// Runtime: 0 ms (100.00%)
// Memory Usage: 6 MB (94.70%)

class Solution {
   public:
    bool strongPasswordCheckerII(string password) {
        static const string kSpecialCharacters = "!@#$%^&*()-+";
        if (password.size() < 8) {
            return false;
        }
        int lowercase_count = 0;
        int uppercase_count = 0;
        int digit_count = 0;
        int special_character_count = 0;
        for (string::size_type i = 0; i != password.size(); ++i) {
            if (i > 0 && password[i] == password[i - 1]) {
                return false;
            }
            if (islower(password[i])) {
                ++lowercase_count;
            } else if (isupper(password[i])) {
                ++uppercase_count;
            } else if (isdigit(password[i])) {
                ++digit_count;
            } else if (kSpecialCharacters.find(password[i]) != string::npos) {
                ++special_character_count;
            }
        }
        return lowercase_count > 0 && uppercase_count > 0 && digit_count > 0 &&
               special_character_count > 0;
    }
};
