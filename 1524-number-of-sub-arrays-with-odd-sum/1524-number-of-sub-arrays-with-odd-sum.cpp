class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long count = 0;
        int prefixSum = 0;
        int oddCount = 0;
        int evenCount = 1; // Empty subarray has sum 0 (even)

        for (int num : arr) {
            prefixSum += num;

            if (prefixSum % 2 == 0) {
                // Even prefix sum pairs with previous odd prefix sums
                count += oddCount;
                evenCount++;
            } else {
                // Odd prefix sum pairs with previous even prefix sums
                count += evenCount;
                oddCount++;
            }
        }

        return count % MOD;
    }
};
