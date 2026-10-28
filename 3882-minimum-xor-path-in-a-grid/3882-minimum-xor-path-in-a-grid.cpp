// #include <vector>
// #include <climits>
// #include <algorithm>

// using namespace std;

// class Solution {
// public:
//     int fun(int i, int j, int current_xor, vector<vector<int>> &grid) {
//         int m = grid.size();
//         int n = grid[0].size();
        
//         // 1. Out of bounds check: Return INT_MAX because this path is invalid
//         if (i >= m || j >= n) return INT_MAX; 
        
//         // 2. Accumulate the current cell's value into our running XOR sum
//         int next_xor = current_xor ^ grid[i][j];
        
//         // 3. Base case: If we reached the bottom-right corner, return the final accumulated XOR sum
//         if (i == m - 1 && j == n - 1) {
//             return next_xor;
//         }
        
//         // 4. Pass the updated XOR sum down to the next steps
//         int down = fun(i + 1, j, next_xor, grid);
//         int right = fun(i, j + 1, next_xor, grid);
        
//         // 5. Now it is safe to take the minimum, because these values represent complete path totals
//         return min(down, right);
//     }

//     int minCost(vector<vector<int>>& grid) {
//         // Start recursion at (0,0) with an initial accumulated XOR value of 0
//         return fun(0, 0, 0, grid);
//     }
// };

#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fun(int i, int j, int current_xor, vector<vector<int>> &grid, vector<vector<vector<int>>> &memo) {
        int m = grid.size();
        int n = grid[0].size();
        
        // 1. Out of bounds check
        if (i >= m || j >= n) return INT_MAX; 
        
        // 2. Accumulate the current cell's value into the running XOR sum
        int next_xor = current_xor ^ grid[i][j];
        
        // 3. Base case: Reached the bottom-right corner
        if (i == m - 1 && j == n - 1) {
            return next_xor;
        }
        
        // 4. Check memo table (using current_xor before applying the new cell, or next_xor)
        // It's cleaner to cache based on the incoming state (i, j, current_xor)
        if (memo[i][j][current_xor] != -1) {
            return memo[i][j][current_xor];
        }
        
        // 5. Explore down and right paths
        int down = fun(i + 1, j, next_xor, grid, memo);
        int right = fun(i, j + 1, next_xor, grid, memo);
        
        // 6. Cache the minimum total path cost found from this state
        return memo[i][j][current_xor] = min(down, right);
    }

    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Dynamically allocate exactly what is needed: m x n x 1024
        // Initialised to -1 (unvisited)
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        
        return fun(0, 0, 0, grid, memo);
    }
};
