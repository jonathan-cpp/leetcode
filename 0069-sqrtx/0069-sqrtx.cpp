class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) 
            return x;

        // Newton's method, with my own estimated guess equation
        long long guess = 1 << static_cast<int>(std::log2(x) / 2 + 1);
        while (guess * guess > x)
            guess = (guess + x / guess) / 2;

        return guess;
    }
};