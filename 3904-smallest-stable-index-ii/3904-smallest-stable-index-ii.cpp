class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre_max(n);
        vector<int> suff_min(n);

        pre_max[0] = nums[0];
        for(int i =1; i<n;i++){
            pre_max[i] = max(nums[i], pre_max[i-1]);
        }
        
        suff_min[n-1] = nums[n-1];
        for(int i =n-2;i>=0; i--){
            suff_min[i] = min(nums[i], suff_min[i+1]);
        }
        int diff;
        for(int i =0; i<n;i++){
            diff = pre_max[i] - suff_min[i];
            if(diff <= k) return i;
        }
        return -1;        
    }
};