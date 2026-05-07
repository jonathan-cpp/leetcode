class Solution {
public:
    int reverse(int x) {
        std::int64_t result = 0;
        while(x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow before multiplying
            // INT_MAX = 2147483647 → last digit 7
            // INT_MIN = -2147483648 → last digit -8
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7))
                return 0;
            if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8))
                return 0;
            
            result = result * 10 + digit;
        }

        return result;
    }
};