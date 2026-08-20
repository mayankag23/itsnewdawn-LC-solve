class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1 || n == 2) return nums;
        vector<int> arr1;
        vector<int> arr2;
        // vector<int> ans;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int last1 = arr1.back();
        int last2 = arr2.back();
        for(int i =2; i<n;i++){
            if(last1 > last2){
                arr1.push_back(nums[i]);
                last1 = arr1.back();
            }
            else{
                arr2.push_back(nums[i]);
                last2 = arr2.back();
            }
        }
        for(auto &it : arr2){
            arr1.push_back(it);
        }
        return arr1;       
        
    }
};