class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int start, end=0;
        int res=2;
        int prodval =1;

        while(end<n){
            while(gcd(prodval, nums[end])>1){
                prodval /= nums[start];
                start++;
            }
            prodval *= nums[end];
            res = max(res, end-start+1);
            end++;
        }
        return res;
    }
};