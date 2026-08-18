class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi=0;
        for(int i = 0; i<n;i++){
            maxi = max(maxi, nums[i]);
        }
        int arr[51] = {0};
        for(int i = 0; i < n; i++){
            arr[nums[i]]++;
        }
        int lowfreq =-1;
        for(int i = 0;i<=50;i++){
            if(arr[i] ==1) lowfreq = i;
        }
        // case 1: largest element of nums array
        if(k==n) return maxi;
        // case 2 : largest elemnet with freq = 1
        if(k==1) {
            if(lowfreq != -1) return lowfreq;
            else return -1;
        }
        // case 3 : check 1st and last element  
        int first = nums[0];
        int last = nums[n-1];
        int cnt1=0, cnt2 =0;
        for(int i = 0; i < n;i++){
            if(nums[i] == first) cnt1++;
            if(nums[i] == last) cnt2++;
        }
        if(cnt1 == cnt2 && cnt1 == 1) return first > last ? first : last;
        if(cnt1 == 1 && cnt2 != 1)  return first;
        if(cnt2 == 1 && cnt1 != 1) return last;
        return -1;
    }
};