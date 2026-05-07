class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x >= 0 && x <= 9) return true;

        int original = x;
        int reversed = 0;

        while (x != 0) {
            // pluck the last digit off x
            int digit = x % 10;

            // remove that digit from x
            x /= 10;

            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7))
                return 0;

            // stick that digit onto the end of reversed
            reversed = reversed * 10 + digit;
        }

        return original == reversed;
    }
};