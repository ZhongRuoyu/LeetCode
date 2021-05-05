// Solved 2021-05-05 14:59
// Runtime: 4 ms (75.97%)
// Memory Usage: 6.8 MB (69.95%)

class Solution {
   public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string alias{generateRandomString()};
        while (tinyurl.find(alias) != tinyurl.end()) {
            alias = generateRandomString();
        }
        tinyurl[alias] = longUrl;
        return (prefix + alias);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if (shortUrl.find(prefix) != 0) return "";
        string alias{shortUrl.substr(19)};
        if (tinyurl.find(alias) == tinyurl.end()) return "";
        return tinyurl[alias];
    }

   private:
    static const string prefix;  // length 19

    static const string validchar;  // length 62

    static unordered_map<string, string> tinyurl;

    string generateRandomString(int length = 6) {
        string str;
        while (length--) {
            str.push_back(validchar[rand() % 62]);
        }
        return str;
    }
};

const string Solution::prefix{"http://tinyurl.com/"};

const string Solution::validchar{
    "0123456789"
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"};

unordered_map<string, string> Solution::tinyurl;

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
