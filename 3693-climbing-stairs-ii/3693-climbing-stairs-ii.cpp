class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if(n==0) return 0;
        
        int prev3=1e9;
        int prev2=1e9;
        int prev1=0;
        
        for(int i =1;i<=n;i++){
            int curr_cost = 1e9;
            curr_cost = min(curr_cost, prev1 + costs[i-1]+ 1*1);
            if(prev2 != 1e9 && i-2 >= 0){
                curr_cost = min(curr_cost, prev2 + costs[i-1] + 2*2);
            }
            if(prev3 != 1e9 && i-3 >= 0){
                curr_cost = min(curr_cost, prev3 + costs[i-1]+ 3*3);
            }
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr_cost;
            // cout << prev1 << " " << prev2 << " " << prev3 << endl;
        }
        return prev1;

    }
};