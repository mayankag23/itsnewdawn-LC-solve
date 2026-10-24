class Solution {
public:

           // Tabulation without space optimise
    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();
    //     vector<vector<int>> dp(m, vector<int> (n,0));
        
    //     for(int i =0;i <m;i++){
    //         for(int j =0;j<n;j++){
    //             if(i ==0 && j ==0){
    //              dp[0][0] = grid[0][0];
    //              continue;
    //             } 
    //             int up;
    //             int left;
    //             if(i>0) up = grid[i][j] + dp[i-1][j];
    //             else up = 1e9;
    //             if(j>0) left = grid[i][j] + dp[i][j-1];
    //             else left = 1e9;

    //             dp[i][j] = min(left, up);
    //         }
    //     }
    //     return dp[m-1][n-1];
    // }

                 // Tabulation with space optimise
     int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n,0);
        
        for(int i =0;i <m;i++){
            vector<int> curr(n,0);
            for(int j =0;j<n;j++){
                if(i ==0 && j ==0){
                 curr[0] = grid[0][0];
                 continue;
                } 
                int up;
                int left;
                if(i>0) up = grid[i][j] + prev[j];
                else up = 1e9;
                if(j>0) left = grid[i][j] + curr[j-1];
                else left = 1e9;

                curr[j] = min(left, up);
            }
            prev = curr;
        }
        return prev[n-1];
        
    }
};