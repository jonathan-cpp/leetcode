class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) 
            return x;

        // Making a good guess in Newton's method can
        // drastically reduce the number of iterations.
        /*
            x=4    (2 bits)   sqrt(x)=2    (1 bit)
            x=16   (4 bits)   sqrt(x)=4    (2 bits)
            x=64   (6 bits)   sqrt(x)=8    (3 bits)
            x=256  (8 bits)   sqrt(x)=16   (4 bits)

            squaring the number, doubles the bits
            square rooting, halves the bits: sqrt(2^n) = 2^(n/2)

            bits of sqrt(x) ≈ bits of x / 2

            log2(x) = y, meaning x lives around the yth bit
            +1 saves iterations by overshooting slightly.
        */
        long long guess = 1 << static_cast<int>(std::log2(x) / 2 + 1);
        
        while (guess * guess > x)
            guess = (guess + x / guess) / 2;

        return guess;
    }
};