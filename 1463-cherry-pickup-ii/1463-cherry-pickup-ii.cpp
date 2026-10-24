class Solution {
public:
    //      //Memoization
    // int fun(int i, int j1, int j2, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid){
    //     int n = grid.size();
    //     int m = grid[0].size();
    //     if(j1<0 || j2<0 || j1>m-1 || j2>m-1) return -1e9;

    //     if(i == n-1){
    //         if(j1==j2) return grid[n-1][j1];
    //         else return grid[n-1][j1]+grid[n-1][j2];
    //     }

    //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

    //     int arr[]= {-1, 0, 1};
    //     int maxi=-1e9;
    //     for(auto p : arr){
    //         for(auto q : arr){
    //             int downpath;
    //             if(j1==j2) downpath = grid[i][j1] + fun(i+1, j1+p, j2+q, dp, grid);
    //             else downpath = grid[i][j1] + grid[i][j2] + fun(i+1, j1+p, j2+q, dp, grid);
    //             maxi = max(maxi, downpath);
    //         }
    //     }   
    //     return dp[i][j1][j2] = maxi; 
    // }
  
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //       //dp[r][c1][c2]
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
    //     return fun(0, 0, m-1, dp, grid);        
    // }

                // Tabulation without space optimise (bottom to top)
    // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //       //dp[r][c1][c2]
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));

    //     for(int j1=0;j1<m;j1++){
    //         for(int j2=0;j2<m;j2++){
    //             if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
    //             else dp[n-1][j1][j2] = grid[n-1][j1]+grid[n-1][j2];
    //         }
    //     }  
    //     int arr[]= {-1,0,1};
    //     for(int i =n-2;i>=0;i--){
    //         for(int j1 =0;j1<m;j1++){
    //             for(int j2=0;j2<m;j2++){
    //                 int maxi= -1e9;
    //                 int uppath;
    //                 for(auto p :arr){
    //                     for(auto q: arr){
    //                         if(j1+p>=0 && j2+q>=0 && j1+p<m && j2+q<m){
    //                             if(j1==j2) uppath = grid[i][j1] + dp[i+1][j1+p][j2+q];
    //                             else uppath = grid[i][j1] + grid[i][j2] + dp[i+1][j1+p][j2+q];
    //                         }
    //                         else{
    //                             uppath = -1e9;
    //                         }
    //                         maxi = max(uppath, maxi);
    //                     }
    //                 }
    //                 dp[i][j1][j2] = maxi;
    //             }
    //         }
    //     }
    //     return dp[0][0][m-1];


                //Tabulation  with space optimise(travel bottom to up)
        // int cherryPickup(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();
    //       //dp[r][c1][c2]
    //     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
    //     return fun(0, 0, m-1, dp, grid);        
    // }

                // Tabulation without space optimise (bottom to top)
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
          //dp[c1][c2]
        vector<vector<int>> front(m, vector<int>(m,-1));  // similar to prev in 2d dp ques
        vector<vector<int>> curr(m, vector<int>(m,-1));

        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) front[j1][j2] = grid[n-1][j1];
                else front[j1][j2] = grid[n-1][j1]+grid[n-1][j2];
            }
        }  
        int arr[]= {-1,0,1};
        for(int i =n-2;i>=0;i--){
            for(int j1 =0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi= -1e9;
                    int uppath;
                    for(auto p :arr){
                        for(auto q: arr){
                            if(j1+p>=0 && j2+q>=0 && j1+p<m && j2+q<m){
                                if(j1==j2) uppath = grid[i][j1] + front[j1+p][j2+q];
                                else uppath = grid[i][j1] + grid[i][j2] + front[j1+p][j2+q];
                            }
                            else{
                                uppath = -1e9;
                            }
                            maxi = max(uppath, maxi);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            front = curr;
        }
        return front[0][m-1];
    }        
};