class Solution {
public:
    int fun(string s, int i, int j){
        int ans =0, bal =0;
        int start = i;

        for(int k=i;k<j; k++){
            if(s[k] == '(') bal = bal + 1;
            else bal = bal-1;

            if(bal == 0){
                if(k-start == 1) ans = ans +1;
                else ans = ans + 2*fun(s, start+1, k);
            start=k+1;
            }   
        }
        return ans;
    }
    int scoreOfParentheses(string s) {
        int n = s.size();
        return fun(s,0, n);
    }
};