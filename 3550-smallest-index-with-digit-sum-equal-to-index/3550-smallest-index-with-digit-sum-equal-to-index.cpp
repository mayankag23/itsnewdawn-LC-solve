class Solution {
public:
    int sumdigits(int n){
        int temp = n;
        int sum=0;
        while(temp>0){
            sum = sum + temp%10;
            temp = temp/10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i <n;i++){
            if(sumdigits(nums[i]) == i){
                return i;
            }
        }
        return -1;        
    }
};