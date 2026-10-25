class Solution {
public:      // Tabulation with space optimisation
    bool subsetsum(vector<int> &nums, int sum){
        int n = nums.size();
        vector<bool> prev(sum+1,false);
        prev[0] =true;
        if(nums[0]<= sum) prev[nums[0]]=true;

        for(int i=1;i<n;i++){
            vector<bool> curr(sum+1,false);
            curr[0] = true;
            for(int target = 1; target<=sum;target++){
                bool nottake = prev[target];
                bool take = false;
                if(nums[i]<=target) take = prev[target-nums[i]];
                curr[target]=take||nottake;
            }
            prev = curr;
        }
        return prev[sum];
    }
    bool canPartition(vector<int>& nums) {
        int totalsum= accumulate(nums.begin(), nums.end(), 0);
        if(totalsum%2 != 0) return false;
        int target = totalsum/2;
        return subsetsum(nums, target);
    }
};