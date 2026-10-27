class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int m = g.size();
        int n = s.size();
        int l=0, r=0;
        while(l<m && r<n){
            if(g[l]<=s[r]){
                l++;
            }
            r++;
        }
        return l;
    }
};