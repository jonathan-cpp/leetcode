class Solution {
public:
    string addBinary(string a, string b) {
        // Overflow problem 
        /*
        return std::bitset<64>(
            std::bitset<64>(a).to_ulong() +
            std::bitset<64>(b).to_ulong()
        ).to_string();
        */
        std::string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0, sum = 0;

        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            if (i >= 0) { sum += a[i--] - '0'; }
            if (j >= 0) { sum += b[j--] - '0'; }

            carry = sum / 2;
            result += static_cast<char>('0' + sum % 2);
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};