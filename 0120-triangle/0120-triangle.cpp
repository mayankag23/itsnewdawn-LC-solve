class Solution {
public:
            //Recursion
//     int fun(vector<vector<int>> triangle, int i, int j){
//         int n = triangle.size();
//         if(i == n-1) return triangle[n-1][j];

//         int down = fun(triangle, i+1, j) + triangle[i][j];
//         int downright = fun(triangle, i+1, j+1) + triangle[i][j];
//         return min(down, downright);
//    }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         return fun(triangle, 0, 0);
//     }

             ///Memoisation
//     int fun(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
//         int n = triangle.size();
//         if(i == n-1) return triangle[n-1][j];
        
//         if(dp[i][j] != -1) return dp[i][j];
//         int down = fun(triangle, i+1, j, dp) + triangle[i][j];
//         int downright = fun(triangle, i+1, j+1, dp) + triangle[i][j];
//         return dp[i][j] = min(down, downright);
//    }
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int n = triangle.size();
//         vector<vector<int>> dp(n, vector<int>(n,-1));
//         return fun(triangle, 0, 0, dp);
//     }

            //Tabulation without space optimise (botton to top)
    // int minimumTotal(vector<vector<int>>& triangle) {
    //     int n = triangle.size();
    //     vector<vector<int>> dp(n, vector<int>(n,-1));
        
    //     for(int j =0; j < n; j++){
    //         dp[n-1][j] = triangle[n-1][j];
    //     }
        
    //     for(int i= n-2; i>=0; i--){
    //         for(int j =i ;j>=0;j--){
    //             int down = triangle[i][j] + dp[i+1][j];
    //             int downright = triangle[i][j] + dp[i+1][j+1];
    //             dp[i][j] = min(down, downright);
    //         }
    //     }
    //     return dp[0][0];
    // }

                 // Tabulation with space optimise (down to up)
      int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> prev =triangle[n-1];

        for(int i= n-2; i>=0; i--){
            vector<int> curr(triangle[i].size(), 0);
            for(int j =i ;j>=0;j--){
                int down = triangle[i][j] + prev[j];
                int downright = triangle[i][j] + prev[j+1];
                curr[j] = min(down, downright);
            }
            prev = curr;
        }
        return prev[0];
    }
};