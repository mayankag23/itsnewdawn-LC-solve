class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m, vector<int>(n, 0)); 
        queue<pair<pair<int, int>, int>> q; //{{r,c}, t}
        int fresh =0;
        for(int i=0;i <m;i++){
            for(int j=0; j <n;j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else vis[i][j] = 0;
                if(grid[i][j] == 1) fresh++;
            }
        }
        int tm =0;
        int cnt =0;
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, -1, 0, +1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            // tm = max(tm ,t);
            q.pop();
            for(int i = 0; i< 4; i++){
                int newr = r + delrow[i];
                int newc = c + delcol[i];
                if(newr >=0 && newr < m && newc >= 0 && newc < n && vis[newr][newc] != 1 && grid[newr][newc] == 1){
                    q.push({{newr, newc}, t+1});
                    vis[newr][newc] = 1;
                    cnt++;
                }
            }
            tm = max(tm ,t);
        }
        if(cnt == fresh) return tm;
        return -1;
    }
};