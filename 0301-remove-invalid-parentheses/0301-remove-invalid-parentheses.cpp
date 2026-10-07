class Solution {
public:
    set<string> ans;
    int mn;

    void dfs(string &s, int i, int l, int r, string &cur, int rem) {
        if (i == s.size()) {
            if (l == r) {
                if (rem < mn) {
                    ans.clear();
                    mn = rem;
                }
                if (rem == mn)
                    ans.insert(cur);
            }
            return;
        }

        if (s[i] != '(' && s[i] != ')') {
            cur += s[i];
            dfs(s, i + 1, l, r, cur, rem);
            cur.pop_back();
            return;
        }

        // Remove s[i]
        dfs(s, i + 1, l, r, cur, rem + 1);

        // Keep s[i]
        cur += s[i];

        if (s[i] == '(')
            dfs(s, i + 1, l + 1, r, cur, rem);
        else if (r < l)
            dfs(s, i + 1, l, r + 1, cur, rem);

        cur.pop_back();
    }

    vector<string> removeInvalidParentheses(string s) {
        mn = INT_MAX;
        string cur;
        dfs(s, 0, 0, 0, cur, 0);

        return vector<string>(ans.begin(), ans.end());
    }
};