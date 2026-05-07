class Solution {
public:
    bool isMatch(string s, string p) {
        //return std::regex_match(s, std::regex(p)); 
        m_memo.clear();
        return helper(s, p, 0, 0); // O(m*n)
    }

private:
    bool helper(string& s, string& p, int si, int pi) {
        // create a unique key for this (si, pi) combination
        string key = to_string(si) + "," + to_string(pi);

        // already computed this before? return cached result
        if (m_memo.count(key)) return m_memo[key];

        // base cases
        if (si == s.size() && pi == p.size()) return true;
        if (pi == p.size()) return false;

        bool currentMatch = si < s.size() && charMatch(s, p, si, pi);

        bool result;

        if (inBounds(p, pi + 1) && p[pi + 1] == '*') {
            result =
                // choice 1: skip "x*" entirely (zero matches)
                helper(s, p, si, pi + 2) ||
                // choice 2: consume s[si], stay on pi (one or more matches)
                (currentMatch && helper(s, p, si + 1, pi));
        } else if (currentMatch) {
            result = helper(s, p, si + 1, pi + 1);
        } else {
            result = false;
        }

        // cache before returning
        m_memo[key] = result;
        return result;
    }

    bool charMatch(string& s, string& p, int si, int pi) {
        return p[pi] == '.' || s[si] == p[pi];
    }

    bool inBounds(string& str, int index) {
        return index >= 0 && index < str.size();
    }

private:
    std::unordered_map<string, bool> m_memo;
};