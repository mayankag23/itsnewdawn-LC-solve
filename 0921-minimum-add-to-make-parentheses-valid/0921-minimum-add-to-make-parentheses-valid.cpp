class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        int mini = 0;
        for(char c: s){
            if(c == '('){
                open++;
            }
            else{
                if(open>0) open--;
                else mini++;
            }
        }
        return mini + open;        
    }
};