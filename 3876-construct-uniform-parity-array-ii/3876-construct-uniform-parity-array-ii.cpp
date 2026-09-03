class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n==1) return true;
        int cnt_odd=0, cnt_even=0;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==0) cnt_odd++;
            else cnt_even++;
        }
        if(cnt_odd == 0 || cnt_even == 0) return true;

        int min_odd = INT_MAX;
        int min_even = INT_MAX;
        
        for(int i =0; i<n;i++){
            if(nums1[i]%2 == 0){
                min_even = min(min_even, nums1[i]);
            }
            else{
                min_odd = min(min_odd, nums1[i]);
            }
        }
        if(min_even < min_odd) return false;
        return true;        
    }
};