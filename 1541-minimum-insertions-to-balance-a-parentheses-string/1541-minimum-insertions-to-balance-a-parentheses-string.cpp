class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int insertions = 0;
        int idx =0;
        int leftcnt =0;
        while(idx < n){
            char c = s[idx];
            if(c == '('){
                leftcnt++;
                idx++;
            }
            else{
                if(leftcnt > 0){
                    leftcnt--;
                }
                else{
                    insertions++;
                }
                if(idx < n-1 && s[idx+1] == ')'){
                    idx += 2;                   
                }
                else{
                    insertions++;
                    idx++;
                }
            }
        }
        insertions += leftcnt *2;
        return insertions;
    }
};