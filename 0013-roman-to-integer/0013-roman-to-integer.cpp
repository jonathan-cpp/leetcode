class Solution {
public:
    int romanToInt(string s) {
        int romanValues[89] = {0};
        romanValues['I'] = 1;
        romanValues['V'] = 5;
        romanValues['X'] = 10;
        romanValues['L'] = 50;
        romanValues['C'] = 100;
        romanValues['D'] = 500;
        romanValues['M'] = 1000;

        int result = 0;

        // rules:
        //  current < next  → subtract
        //  current >= next → add 

        for (int i = 0; i < s.size(); i++) {
            int current = romanValues[s[i]];
            int next    = (i + 1 < s.size()) ? romanValues[s[i + 1]] : 0;

            if (current < next) 
                result -= current;
            else
                result += current;
        }

        return result;
    }
};