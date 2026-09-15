class Solution {
public:

    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    int maxPalindromes(string s, int k) {

        int n = s.size();

        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--) {

            // case 1 :Don't take a palindrome starting at i
            dp[i] = dp[i + 1];

            // Try every possible ending point
            for(int j = i + k - 1; j < n; j++) {

                if(isPalindrome(s, i, j)) {

                    dp[i] = max(
                        dp[i],
                        1 + dp[j + 1]
                    );
                }
            }
        }

        return dp[0];
    }
};