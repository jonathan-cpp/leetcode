class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) 
            return x;

        // Newton's method
        long long guess = x;
        while (guess * guess > x)
            guess = (guess + x / guess) / 2;

        return guess;
    }
};