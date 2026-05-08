class Solution {
public:
    int climbStairs(int n) {
        // pattern: Fibonacci...
        // each answer is the sum of the two before it
        // f(n) = f(n-1) + f(n-2)

        // Binet's formula — O(1) time  O(1) space
        // loses precision for n > 70 due to floating point
        double phi = (1.0 + sqrt(5.0)) / 2.0;
        return static_cast<int>(round(pow(phi, n + 1) / sqrt(5.0)));
    }

private:
    // recursive — O(2^n) time  O(n) space
    int fib_recursive(int n) {
        if (n <= 1) return n;
        return fib_recursive(n-1) + fib_recursive(n-2);
    }

    // memoized — O(n) time  O(n) space
    int fib_memoized(int n, std::vector<int>& memo) {
        if (n <= 1) return n;
        if (memo[n] != -1) return memo[n];
        return memo[n] = fib_memoized(n-1, memo) + fib_memoized(n-2, memo);
    }

    // iterative — O(n) time  O(1) space
    int fib_iterative(int n) {
        if (n <= 1) return n;
        int prev2 = 0, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};