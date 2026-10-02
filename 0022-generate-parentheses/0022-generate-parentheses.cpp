class Solution {
public:
    void backtrack(int open, int close, int n, vector<string> &ans, string &curr){
        if(close == n && open == n){
            ans.push_back(curr);
            return;
        }
        if(open < n){
            curr.push_back('(');
            backtrack(open+1, close, n, ans, curr);
            curr.pop_back();
        }
        if(close < open){
            curr.push_back(')');
            backtrack(open, close+1, n, ans, curr);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        backtrack(0, 0, n, ans, curr);
        return ans;        
    }
};