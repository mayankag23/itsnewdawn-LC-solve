class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int cnt = 0;
        int maxi = INT_MIN;
        for(char c : s){
            if(c == '('){
                cnt++;
            }
            if(c ==')'){
                cnt--;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};