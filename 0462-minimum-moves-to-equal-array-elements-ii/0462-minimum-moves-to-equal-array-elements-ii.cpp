class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int k = n/2;

        int sum =0;
        for(int i=0;i<n;i++){
            sum = sum + abs(nums[i] - nums[k]);
        }
        return sum;
    }
};