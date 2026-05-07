class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> lastSeenAt;
        int windowStart = 0, longest = 0;

        for (int windowEnd = 0; windowEnd < s.size(); windowEnd++) {
            char c = s[windowEnd];

            // Check if c is a duplicate inside our current window
            // index:  0  1  2  3  4  5  6  7
            //         a  b  c  a  b  c  b  b
            //                  [  window   ]

            if (lastSeenAt.count(c) && lastSeenAt[c] >= windowStart) {
                // move windowStart past the previous occurrence to remove the duplicate
                windowStart = lastSeenAt[c] + 1;
            }

            lastSeenAt[c] = windowEnd;

            longest = std::max(longest, windowEnd - windowStart + 1);
        }

        return longest;
    }
};