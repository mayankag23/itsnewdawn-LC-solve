// class Solution {
// public:
//     int fxn(vector<int> & nums, int ind, vector<int> &dp){
//         if(ind == 0) return nums[ind];
//         if(ind < 0) return 0;
//         if(dp[ind] != -1) return dp[ind];
//         int pick = nums[ind] + fxn(nums, ind-2, dp);
//         int not_pick = 0 + fxn(nums, ind-1, dp);
        
//         return dp[ind] = max(pick, not_pick);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, -1);
//         int ind = n-1;
//         return fxn(nums, ind, dp);
    
//     }
// };


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int prev1 = nums[0];
        int prev2 = 0;
        for(int i = 1;i < n; i++){
            int take = nums[i];
            if(i > 1) take += prev2;
            int not_take = 0 + prev1;
            int curr = max(take, not_take);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

