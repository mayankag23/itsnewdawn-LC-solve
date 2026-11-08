class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_count(m, 0);
        vector<int> col_count(n, 0);
        
        // First pass: count servers in each row and column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    row_count[i]++;
                    col_count[j]++;
                }
            }
        }
        
        int total_communicating_servers = 0;
        
        // Second pass: count servers that share a row or column with another
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (row_count[i] > 1 || col_count[j] > 1) {
                        total_communicating_servers++;
                    }
                }
            }
        }
        
        return total_communicating_servers;
    }
};
