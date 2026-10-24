class Solution {
public:
         //Memoization
    int fun(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        if(j1<0 || j2<0 || j1>m-1 || j2>m-1) return -1e9;

        if(i == n-1){
            if(j1==j2) return grid[n-1][j1];
            else return grid[n-1][j1]+grid[n-1][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int arr[]= {-1, 0, 1};
        int maxi=-1e9;
        for(auto p : arr){
            for(auto q : arr){
                int downpath;
                if(j1==j2) downpath = grid[i][j1] + fun(i+1, j1+p, j2+q, dp, grid);
                else downpath = grid[i][j1] + grid[i][j2] + fun(i+1, j1+p, j2+q, dp, grid);
                maxi = max(maxi, downpath);
            }
        }   
        return dp[i][j1][j2] = maxi; 
    }
  
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
        return fun(0, 0, m-1, dp, grid);        
    }
};