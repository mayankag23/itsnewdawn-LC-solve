class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int incmaxi =1;
        int decmaxi =1;
        int ans =1;
        for(int i=1; i<n;i++){
            if(nums[i]<nums[i-1]){
                incmaxi++;
                decmaxi=1;
            }
            else if(nums[i]>nums[i-1]){
                incmaxi=1;
                decmaxi++;
            }
            else{
                incmaxi =1;
                decmaxi=1;
            }
            ans = max(ans, max(incmaxi, decmaxi));
        }
        return ans;
    }
};