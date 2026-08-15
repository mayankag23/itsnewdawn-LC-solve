class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int totalxor = 0;
        bool allzero = true;
        for(auto x : nums){
            totalxor = totalxor ^ x;
            if(x>0) allzero = false;
        }
        if(totalxor > 0){
            return n;
        }
        if(allzero){
            return 0;
        }
        else return n-1;
    }
};