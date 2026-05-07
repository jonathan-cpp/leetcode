class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        string output = "";
        int cycle = 2 * numRows - 2;  // repeatable pattern/cycle

        for (int row = 0; row < numRows; row++) {
            // jump through s by cycle
            for (int col = row; col < s.size(); col += cycle) {
                output += s[col];

                int diagonal = col + cycle - 2 * row;
                bool isMiddleRow = row != 0 && row != numRows - 1;
                bool inBounds    = diagonal < s.size();

                if (isMiddleRow && inBounds) {
                    output += s[diagonal];
                }
            }
        }

        return output;
    }
};