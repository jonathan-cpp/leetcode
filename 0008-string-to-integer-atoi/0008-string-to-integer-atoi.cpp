class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        int result = 0;

        // check following order: whitespace → sign → digits → clamp

        // whitespace
        while (i < s.size() && s[i] == ' ') i++;

        // sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // digits
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';  // convert char to int, '3' - '0' = 3

            // clamp BEFORE multiplying
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};