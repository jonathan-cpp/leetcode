class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto it = std::find_if(digits.rbegin(), digits.rend(),
            [](int d) { return d != 9; });

        if (it == digits.rend()) {
            // [9,9,9] -> [1,0,0,0]
            std::fill(digits.begin(), digits.end(), 0);
            digits[0] = 1;
            digits.push_back(0);
        } else {
            (*it)++;
            std::fill(digits.rbegin(), it, 0);
        }

        return digits;
    }
};