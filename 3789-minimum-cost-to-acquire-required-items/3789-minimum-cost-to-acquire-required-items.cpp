class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int min_need = min(need1, need2);
        int min_cost= min(costBoth, cost1+cost2);
        long long ans=0;
        ans += (long long)min_need*min_cost;
        int rem1_need = need1-min_need;
        int rem2_need = need2-min_need;
        ans += 1LL*(min(costBoth, cost1))*rem1_need;
        ans += 1LL*(min(costBoth, cost2))*rem2_need;
        return ans;
    }
};