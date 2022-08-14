// Solved 2022-08-14
// Runtime: 0 ms (100.00%)
// Memory Usage: 8.9 MB (12.74%)

class Solution {
   public:
    string validIPAddress(string queryIP) {
        if (validIPv4Address(queryIP)) {
            return "IPv4";
        }
        if (validIPv6Address(queryIP)) {
            return "IPv6";
        }
        return "Neither";
    }

   private:
    bool validIPv4Address(string queryIP) {
        static const string ipv4_chunk =
            "([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
        static const regex ipv4_regex("^(" + ipv4_chunk + "\\.){3}" +
                                      ipv4_chunk + "$");
        smatch match;
        return regex_match(queryIP, match, ipv4_regex);
    }

    bool validIPv6Address(string queryIP) {
        static const string ipv6_chunk = "([0-9A-Fa-f]{1,4})";
        static const regex ipv6_regex("^(" + ipv6_chunk + "\\:){7}" +
                                      ipv6_chunk + "$");
        smatch match;
        return regex_match(queryIP, match, ipv6_regex);
    }
};
