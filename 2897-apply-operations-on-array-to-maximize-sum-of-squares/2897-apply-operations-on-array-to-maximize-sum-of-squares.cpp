class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> cnt(30, 0);
        
        // make the cnt arr for counting the total 1's in all no at their bit position
        for (int x : nums)
            for (int b = 0; b < 30; b++)
                if (x & (1 << b))
                    cnt[b]++;

        long long ans = 0;

        while (k--) {
            long long x = 0;

            for (int b = 29; b >= 0; b--) {
                if (cnt[b]) {
                    x |= (1LL << b);
                    cnt[b]--;
                }
            }

            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};