class Solution {
public:
        //    Recursion
    // int fun(int row, int col){
    //     if(row == 0 && col == 0) return 1;
    //     if(row < 0 || col < 0) return 0;
    //     int left = fun(row, col-1);
    //     int up = fun(row-1, col);
    //     return up+left;
    // }
    // int uniquePaths(int m, int n) {
    //     return fun(n-1,m-1);
    // }

            // Memoisation
    // int fun(int row, int col, vector<vector<int>> &dp){
    //     if(row == 0 && col == 0) return 1;
    //     if(row < 0 || col < 0) return 0;
    //     if(dp[row][col] != -1) return dp[row][col];
    //     int left = fun(row, col-1, dp);
    //     int up = fun(row-1, col, dp);
    //     return dp[row][col] = up+left;
    // }
    // int uniquePaths(int m, int n) {
    //     vector<vector<int>> dp(m, vector<int>(n ,-1));
    //     return fun(m-1,n-1, dp);
    // }

           // Tabulation without space optimise
    // int uniquePaths(int m, int n) {
    //     int dp[m][n];
    //     for(int i=0;i <m;i++){
    //         for(int j =0; j<n; j++){
    //             if(i == 0 && j == 0) dp[i][j]=1;
    //             else{
    //                 int up = 0;
    //                 int left = 0;
    //                 if(i>0) up =dp[i-1][j];
    //                 if(j>0) left = dp[i][j-1];
    //                 dp[i][j] = up + left;
    //             }
    //         }
    //     }
    //     return dp[m-1][n-1];

            // Tabulation with space optimise
    int uniquePaths(int m, int n) {
        vector<int> prev(n,0);
        for(int i=0;i <m;i++){
            vector<int> curr(n, 0);
            for(int j =0; j<n; j++){
                if(i == 0 && j == 0) curr[j]=1;
                else{
                    int up = 0;
                    int left = 0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = up + left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};