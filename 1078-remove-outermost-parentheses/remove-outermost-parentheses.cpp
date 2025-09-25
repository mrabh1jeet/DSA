class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int balance = 0;  // track nesting depth

        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {   // not outermost
                    result.push_back(c);
                }
                balance++;
            } else { // c == ')'
                balance--;
                if (balance > 0) {   // not outermost
                    result.push_back(c);
                }
            }
        }

        return result;
    }
};
