class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        
        // Direction vectors for 4-directional traversal
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        
        // Queue for iterative BFS to prevent deep recursion stack overhead
        queue<pair<int, int>> q;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If it is land (> 0), it hasn't been visited yet
                if (grid[i][j] > 0) {
                    
                    // We will accumulate the island sum using long long to prevent integer overflow
                    long long islandsum = 0; 
                    
                    // Push the starting cell into queue and mark it visited in-place
                    q.push({i, j});
                    islandsum += grid[i][j];
                    grid[i][j] = 0; // Marking as 0 means "visited/water" so we don't process it again
                    
                    // Standard Iterative BFS loop
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        for (int d = 0; d < 4; d++) {
                            int newrow = r + delrow[d];
                            int newcol = c + delcol[d];
                            
                            // Bounds check and land check
                            if (newrow >= 0 && newcol >= 0 && newrow < m && newcol < n && grid[newrow][newcol] > 0) {
                                islandsum += grid[newrow][newcol];
                                
                                // Crucial step: Mark as visited IMMEDIATELY before pushing to queue 
                                // to prevent the same cell from being added multiple times!
                                grid[newrow][newcol] = 0; 
                                q.push({newrow, newcol});
                            }
                        }
                    }
                    
                    // Check divisibility condition
                    if (islandsum % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
