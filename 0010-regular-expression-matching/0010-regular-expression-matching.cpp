class Solution {
public:
    bool isMatch(string s, string p) {
        return std::regex_match(s, std::regex(p));
    }
};