class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n;i++){
            prefix[i+1] = prefix[i]+nums[i];
        }
        int best = INT_MAX;
        for(int i= l; i <= n;i++){
            for(int j = l; j <= min(r, i); j++){
                int sum = prefix[i] - prefix[i-j];
                if(sum > 0 && sum < best) best = sum;
            }
        }
        if(best == INT_MAX) return -1;
        return best;
    }
};