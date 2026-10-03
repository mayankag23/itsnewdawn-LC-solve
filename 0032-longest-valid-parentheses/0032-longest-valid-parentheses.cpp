#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    int longestValidParentheses(std::string s) {
        std::stack<int> st;
        // Base index to handle edge cases where a valid substring starts from index 0
        st.push(-1); 
        int max_len = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                // Push the index of the opening parenthesis
                st.push(i);
            } else {
                // Pop the top element for a closing parenthesis
                st.pop();

                if (st.empty()) {
                    // If the stack is empty, this ')' is unmatched.
                    // Push its index to serve as the new base boundary.
                    st.push(i);
                } else {
                    // Calculate the length of the current valid substring
                    max_len = std::max(max_len, i - st.top());
                }
            }
        }

        return max_len;
    }
};
