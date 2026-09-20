class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int ans =0;

        for(int i =1; i<=n; i++){
            char c = s[i-1];
            ans = ans+ i*(26-(c-'a'));
        }
    return ans;        
    }
};