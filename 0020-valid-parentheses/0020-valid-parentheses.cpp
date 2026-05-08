class Solution {
public:
    bool isValid(string s) {
        std::stack<char> bracketStack;

        for (char current : s) {
            if (current == '(' || current == '{' || current == '[') {
                bracketStack.push(current);
            } else {
                if (bracketStack.empty()) return false;

                char lastOpen = bracketStack.top();
                bracketStack.pop();

                if (current == ')' && lastOpen != '(') return false;
                if (current == '}' && lastOpen != '{') return false;
                if (current == ']' && lastOpen != '[') return false;
            }
        }

        return bracketStack.empty();
    }
};