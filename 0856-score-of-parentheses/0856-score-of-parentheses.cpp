// class Solution {
// public:
    //  Brute solution
     
//     int fun(string s, int i, int j){
//         int ans =0, bal =0;
//         int start = i;

//         for(int k=i;k<j; k++){
//             if(s[k] == '(') bal = bal + 1;
//             else bal = bal-1;

//             if(bal == 0){
//                 if(k-start == 1) ans = ans +1;
//                 else ans = ans + 2*fun(s, start+1, k);
//             start=k+1;
//             }   
//         }
//         return ans;
//     }
//     int scoreOfParentheses(string s) {
//         int n = s.size();
//         return fun(s,0, n);
//     }
// };


class Solution {
public:

    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(char c : s){
            if(c=='('){
                st.push(0);
            }
            else{
                int u = st.top();
                st.pop();
                int v = st.top();
                st.pop();
                st.push(v + max(1, 2*u));
            }
        }
        return st.top();
    }
};