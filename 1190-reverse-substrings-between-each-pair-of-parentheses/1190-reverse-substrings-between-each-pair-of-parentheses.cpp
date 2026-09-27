class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        string result;
        stack<int> st;
        for(char c : s){
            if(c == '('){
                st.push(result.length());
            }
            else if(c == ')'){
                int start = st.top();
                st.pop();
                reverse(result.begin() + start, result.end());
            }
            else{
                result += c;
            }
        }
        return result;
    }
};