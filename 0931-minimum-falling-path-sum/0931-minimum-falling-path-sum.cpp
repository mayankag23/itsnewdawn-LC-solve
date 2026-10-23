class Solution {
public:
    // Tabulation with space optimise - bottom(prev) to top(curr)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(n, 0);
        for(int i =0; i<n;i++) prev[i]=matrix[n-1][i];
        
        for(int i =n-2; i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0; j<n; j++){
                int downleft = 1e9;
                int down = prev[j];
                int downright = 1e9;
                if(j > 0){
                    downleft = prev[j-1];
                }
                if(j<n-1){
                    downright = prev[j+1];
                }
                int best = min(down, min(downleft, downright));
                curr[j] = best + matrix[i][j];
            }
            prev = curr;
        }
        return *min_element(prev.begin(), prev.end());
    }
};