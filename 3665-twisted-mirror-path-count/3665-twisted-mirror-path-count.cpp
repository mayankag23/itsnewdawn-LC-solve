class Solution {
public:
    int MOD= 1e9+7;
    int fun(int i, int j, int dir, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(i > m-1 || j > n-1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        
        if(grid[i][j] == 1){
            if(dir==0){
                return dp[i][j][dir] = fun(i+1, j, 1, grid, dp);
            }
            else return dp[i][j][dir] = fun(i, j+1, 0, grid, dp);
        }
        else {
            int moveRight = fun(i, j + 1, 0, grid, dp);
            int moveDown = fun(i + 1, j, 1, grid, dp);

            return dp[i][j][dir] = (moveRight + moveDown) % MOD;
        }

    }
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        // 0- right     1 - down
        int right = fun(0, 1, 0, grid, dp);
        int down = fun(1, 0, 1, grid, dp);
        return (right + down) % MOD;        
    }
};