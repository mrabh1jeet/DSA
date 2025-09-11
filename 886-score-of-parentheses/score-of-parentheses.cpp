class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int score = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(-1); // marker
            } else {
                if (st.top() == -1) {
                    st.pop();
                    st.push(1); // "()" = 1
                } else {
                    int sum = 0;
                    while (!st.empty() && st.top() != -1) {
                        sum += st.top();
                        st.pop();
                    }
                    st.pop(); // remove marker
                    st.push(2 * sum);
                }
            }
        }

        int total = 0;
        while (!st.empty()) {
            total += st.top();
            st.pop();
        }
        return total;
    }
};
