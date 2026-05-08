class Solution {
public:
    bool canWinNim(int n) {
        // pattern: every multiple of 4 is a loss.
        return (n % 4) != 0;
    }
};