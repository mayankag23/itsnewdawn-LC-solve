class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        // If there are no numbers with remainder 1 or 2,
        // Alice cannot make the sum non-zero mod 3.
        if (cnt[1] == 0 && cnt[2] == 0)
            return false;

        // If cnt0 is even, the 0-mod-3 stones effectively
        // don't change the remainder situation.
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // If cnt0 is odd, Alice can win if one side has
        // sufficiently more stones than the other.
        return abs(cnt[1] - cnt[2]) > 2;
    }
};