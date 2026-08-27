class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l =0;
        int mini =INT_MAX;
        int ones =0;
        int start =-1;
        for(int r = 0; r <n; r++){
            if(s[r] == '1') ones ++;
            while(ones == k){
                int len = r-l+1;
                if(len < mini){
                    mini = len;
                    start = l;
                }
                else if(len == mini){
                    if(start == -1 || s.substr(l, len) < s.substr(start, mini)){
                        start = l;
                    }
                }
                if(s[l] == '1'){
                    ones--;
                }
                l++;
            } 
        }
        if(start == -1) return "";  
        return s.substr(start, mini);        
    }
};