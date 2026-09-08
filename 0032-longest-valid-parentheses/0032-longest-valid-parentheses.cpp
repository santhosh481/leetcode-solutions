class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Boundary before the current valid substring
        st.push(-1);

        int maxLength = 0;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }
            else {

                st.pop();

                if (st.empty()) {
                    // Current ')' cannot be matched
                    st.push(i);
                }
                else {
                    // Length of valid substring
                    maxLength = max(maxLength, i - st.top());
                }
            }
        }

        return maxLength;
    }
};