class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(nums[i]<0) nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        long long pos=0;
        long long neg =0;
        for(int i = n-1;i >= n/2; i--){
            pos += nums[i]*nums[i];
        }
        for(int i =0; i <n/2; i++){
            neg += nums[i]*nums[i];
        }
        return pos-neg;
    }
};