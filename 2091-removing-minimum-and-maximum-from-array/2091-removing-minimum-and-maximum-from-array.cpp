class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int maxi_ind = -1, mini_ind= -1;

        for(int i =0; i<n; i++){
            if(nums[i] > maxi){
                maxi_ind = i;
                maxi = nums[i];
            }
            if(nums[i] < mini){
                mini_ind = i;
                mini = nums[i];
            }
        }
        int left = max(maxi_ind, mini_ind) + 1;

        int right = n - min(maxi_ind, mini_ind);

        int both = min(maxi_ind, mini_ind) + 1 + n - max(maxi_ind, mini_ind);

        return min({left, right, both});
    }
};