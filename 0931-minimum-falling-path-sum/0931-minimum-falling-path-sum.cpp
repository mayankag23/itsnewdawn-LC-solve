class Solution {
public:

            // Memoisation bottom to top
    // int fun(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
    //     int n = matrix.size();

    //     if(j<0 || j>n-1) return 1e9;
    //     if(i==0) return matrix[0][j];

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int up = matrix[i][j] + fun(i-1, j, matrix, dp);
    //     int upleft = matrix[i][j] + fun(i-1, j-1, matrix, dp);
    //     int upright = matrix[i][j] + fun(i-1, j+1, matrix, dp);

    //     return dp[i][j] = min(up, min(upleft, upright));
    // }
    // int minFallingPathSum(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     vector<vector<int>> dp(n, vector<int>(n,-1));
    //     int ans=INT_MAX;
    //     for(int j =0; j <n;j++){
    //         ans = min(ans, fun(n-1,j,matrix, dp));
    //     }
    //     return ans;
    // }

    
    // Tabulation with space optimise - top (row0)(prev) to bottom row(n-1)(curr)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        for(int i =0; i<n;i++) prev[i]=matrix[0][i];
        
        for(int i =1; i<n;i++){
            vector<int> curr(n,0);
            for(int j=0; j<n; j++){
                int downleft = 1e9;
                int down = prev[j];
                int downright = 1e9;
                if(j > 0){
                    downleft = prev[j-1];
                }
                if(j<n-1){
                    downright = prev[j+1];
                }
                int best = min(down, min(downleft, downright));
                curr[j] = best + matrix[i][j];
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};