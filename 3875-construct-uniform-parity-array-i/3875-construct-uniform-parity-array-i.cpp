class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        if(n==1 || n==2) return true;

        int cnt0 =0, cnt1 =0;
        for(int i =0; i<n;i++){
            if(nums1[i]%2 == 0) cnt0++;
            else cnt1++;
        }
        if(cnt1 == 1) return true;
        return true;
        
    }
};