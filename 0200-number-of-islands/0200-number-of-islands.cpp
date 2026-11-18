class Solution {
public:
    void dfs(int i, int j, int ans, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[i][j]=1;
        int m = grid.size();
        int n = grid[0].size();
        int row[] ={-1,1,0,0};
        int col[] ={0,0,1,-1};

        for(int p=0;p<4;p++){
            int nrow = i+row[p];
            int ncol = j+col[p];
            if(nrow>=0 && ncol >= 0 && nrow<m && ncol < n && vis[nrow][ncol] == -1 && grid[nrow][ncol]=='1'){
                dfs(nrow, ncol, ans, vis, grid);
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,-1));
         
        int ans =0;
        for(int i =0;i <m;i++){
            for(int j=0;j < n; j++){
                if(grid[i][j] == '1' && vis[i][j] == -1){
                    dfs(i, j, ans, vis, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};