class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        int l = 0;
        int ans = 0;
        unordered_map<int, int> mpp;

        for(int r = 0; r<n;r++){
            mpp[s[r]]++;
            while(mpp[s[r]] > 2){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};