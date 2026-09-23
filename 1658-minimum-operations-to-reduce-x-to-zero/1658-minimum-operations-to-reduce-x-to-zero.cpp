class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        
        if(target < 0) return -1;
        if(target == 0) return n;

        int sum =0;
        int length = -1;
        int l = 0;
        for(int r = 0; r<n; r++){
            sum = sum + nums[r];
            while(sum > target && l < r){
                sum = sum - nums[l];
                l++;
            }
            if(sum == target){
                length = max(length, r-l+1);
            }
        }
        if(length == -1) return -1;
        else  return n-length;
    }
};