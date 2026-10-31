// class Solution {
// public:
//     int MOD= 1e9+7;
//     int fun(int i, int j, int dir, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp){
//         int m = grid.size();
//         int n = grid[0].size();

//         if(i > m-1 || j > n-1) return 0;
//         if(i == m-1 && j == n-1) return 1;
//         if(dp[i][j][dir] != -1) return dp[i][j][dir];
        
//         if(grid[i][j] == 1){
//             if(dir==0){
//                 return dp[i][j][dir] = fun(i+1, j, 1, grid, dp);
//             }
//             else return dp[i][j][dir] = fun(i, j+1, 0, grid, dp);
//         }
//         else {
//             int moveRight = fun(i, j + 1, 0, grid, dp);
//             int moveDown = fun(i + 1, j, 1, grid, dp);

//             return dp[i][j][dir] = (moveRight + moveDown) % MOD;
//         }

//     }
//     int uniquePaths(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
//         // 0- right     1 - down
//         int right = fun(0, 1, 0, grid, dp);
//         int down = fun(1, 0, 1, grid, dp);
//         return (right + down) % MOD;        
//     }
// };



class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size(); // Handling rectangular grids safely
        int MOD = 1e9 + 7;

        // Base Check: If start or destination is a mirror, no valid path exists
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) return 0;

        // Step 1: Declare a 2D DP array initialized with 0
        // dp[i][j] stores the number of valid paths from empty cell (i, j) to destination
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Step 2: Base Case initialization
        dp[m - 1][n - 1] = 1;

        // Step 3: Run nested loops to compute states bottom-up
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                
                // Skip the destination cell as it's already solved
                if (i == m - 1 && j == n - 1) continue;

                // We only compute paths starting from empty cells
                if (grid[i][j] == 0) {
                    
                    // --- Choice 1: Attempt to move RIGHT ---
                    int rI = i, rJ = j + 1, rDir = 0; // rDir = 0 means moving right
                    
                    // Simulate continuous mirror reflections inline
                    while (rI < m && rJ < n && grid[rI][rJ] == 1) {
                        if (rDir == 0) {
                            rI = rI + 1; // Turned DOWN, move 1 step down
                            rDir = 1;
                        } else {
                            rJ = rJ + 1; // Turned RIGHT, move 1 step right
                            rDir = 0;
                        }
                    }
                    int moveRight = (rI < m && rJ < n) ? dp[rI][rJ] : 0;


                    // --- Choice 2: Attempt to move DOWN ---
                    int dI = i + 1, dJ = j, dDir = 1; // dDir = 1 means moving down
                    
                    // Simulate continuous mirror reflections inline
                    while (dI < m && dJ < n && grid[dI][dJ] == 1) {
                        if (dDir == 0) {
                            dI = dI + 1; // Turned DOWN, move 1 step down
                            dDir = 1;
                        } else {
                            dJ = dJ + 1; // Turned RIGHT, move 1 step right
                            dDir = 0;
                        }
                    }
                    int moveDown = (dI < m && dJ < n) ? dp[dI][dJ] : 0;


                    // Total valid paths from the current empty cell
                    dp[i][j] = (moveRight + moveDown) % MOD;
                }
            }
        }

        // Return paths starting from the top-left corner (0,0)
        return dp[0][0];
    }
};

