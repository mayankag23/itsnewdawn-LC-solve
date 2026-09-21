class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n =  nums.size();
        vector<long long> ans(k,0);
        vector<long long> dp(k,0);

        for(int i =0; i<n;i++){
            vector<long long> currdp(k,0);
            currdp[nums[i] % k]++;

            for(int r =0; r<k; r++){
                int newrem = (r*(nums[i] %k)) % k;
                currdp[newrem] = currdp[newrem] + dp[r]; 

            }
            for(int r=0; r<k;r++){
                ans[r] = ans[r] + currdp[r];
            }
            dp = currdp;
            
        }
        return ans;       
        
    }
};