class Solution {
public:
    int climbStairs(int n) {
        // pattern: Fibonacci...
        // each answer is the sum of the two before it
        // f(n) = f(n-1) + f(n-2)

        // Binet's formula:
        double phi = (1.0 + sqrt(5.0)) / 2.0;
        return static_cast<int>(round(pow(phi, n + 1) / sqrt(5.0)));
    }
};