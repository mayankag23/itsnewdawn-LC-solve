class Solution {
// Brute method : giving TLE

// private:
//     vector<int> digits(int n){
//         int temp = n;
//         int cnt=0;
//         int sum =0, sq =0;
//         vector<int> ans;
//         while(temp > 0){
//             sum = sum + temp%10;
//             sq = sq + (temp%10)*(temp%10);
//             temp = temp/10;
//             cnt++;
//         }
//         ans.push_back(cnt);
//         ans.push_back(sum);
//         ans.push_back(sq);
//         return ans;
//     }

// public:
//     string maxSumOfSquares(int num, int sum) {
//         int l = pow(10, num-1);
//         int r = pow(10, num);
//         int maxi = INT_MIN;
//         int ans=0;
//         for(int i = l; i< r; i++){
//             vector<int> arr = digits(i);
//             if(arr[0] == num && arr[1] == sum){
//                 if(arr[2] >= maxi){
//                     maxi = arr[2];
//                     ans = i;
//                 }
//             }    
//         }
//         if(ans !=0 ) return to_string(ans);
//         return "";
//     }
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num ) return "";

        string ans="";
        for(int i =0;i <num;i++){
            int d = min(9, sum);
            ans += char('0'+ d);
            sum = sum - d;
        }
        if(sum == 0) return ans;
        return "";
    }    
};