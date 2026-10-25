class Solution {
public:

    void dfs(int row, int col, vector<vector<int>> & vis, vector<vector<int>> &grid){
        int n= grid.size();
        int m = grid[0].size();
        vis[row][col]=1;
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        
            for(int i =0; i<4;i++){
                int newrow = row+delrow[i];
                int newcol = col+delcol[i];
                if(newrow >= 0 && newcol >=0 && newrow <n && newcol <m && grid[newrow][newcol] == 0 && vis[newrow][newcol]==0){
                    dfs(newrow, newcol, vis, grid);
                }
            }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int, int>> q;
        //boundary traversal
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                    vis[i][j]=1;
                    q.push({i,j});
                }
                }
            }
        }
        //bfs
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
                for(int i=0;i<4;i++){
                    int newrow = row+delrow[i];
                    int newcol = col+delcol[i];
                    if(newrow >= 0 && newcol >=0 && newrow <n && newcol <m && vis[newrow][newcol] == 0 && grid[newrow][newcol] == 0){
                        q.push({newrow, newcol});
                        vis[newrow][newcol]=1;
                    }
                }
        } 
        //cnt by dfs
        int cnt =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 && vis[i][j]==0){ //still unvisited
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }    
        return cnt;                                                         
    }
};