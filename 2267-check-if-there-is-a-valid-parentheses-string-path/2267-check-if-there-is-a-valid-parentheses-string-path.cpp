class Solution {
public:
    int m, n;
    int memo[100][100][200];
    //-1 == not visited  //0 == not possible // 1 == possible
    bool dfs(int row, int col, int balance, vector<vector<char>> &grid){
        balance += grid[row][col] == '(' ? 1 : -1;
        int remaining = m-1-row + n-1-col;

        if(balance < 0 || balance > remaining) return false;
        if(row == m-1 && col == n-1) return balance==0;
        
        if(memo[row][col][balance] != -1) return memo[row][col][balance];

        bool possible = false;
        if(row < m-1) possible = possible || dfs(row+1, col, balance, grid);
        if(col < n-1) possible = possible || dfs(row, col + 1, balance, grid);
        
        memo[row][col][balance] = possible;
        return memo[row][col][balance];
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int length = m + n -1;
        
        if(length %2 != 0 || grid[0][0] == ')' || grid[m-1][n-1] == '(') return false;
        memset(memo, -1,  sizeof(memo));
        return dfs(0, 0, 0, grid);   
    }
};