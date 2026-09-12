class Solution {
public:

    struct State {
        long long score;
        vector<int> indices;
    };

    int n;

    vector<vector<State>> memo;
    vector<vector<bool>> vis;

    // Returns first index j such that intervals[j][0] > end
    int getNext(vector<vector<int>>& intervals, int end) {

        int l = 0;
        int r = n;

        while(l < r) {

            int mid = l + (r - l) / 2;

            if(intervals[mid][0] > end)
                r = mid;
            else
                l = mid + 1;
        }

        return l;
    }

    bool smaller(vector<int>& a, vector<int>& b) {
        return lexicographical_compare(
            a.begin(), a.end(),
            b.begin(), b.end()
        );
    }

    State dfs(int i, int k, vector<vector<int>>& intervals) {

        if(i == n || k == 0)
            return {0, {}};

        if(vis[i][k])
            return memo[i][k];

        vis[i][k] = true;

        // Option 1: skip current interval
        State skip = dfs(i + 1, k, intervals);

        // Option 2: take current interval
        int next = getNext(intervals, intervals[i][1]);

        State nxt = dfs(next, k - 1, intervals);

        State take;

        take.score = intervals[i][2] + nxt.score;

        take.indices = nxt.indices;
        take.indices.push_back(intervals[i][3]);

        sort(take.indices.begin(), take.indices.end());

        // Decide between take and skip
        State ans;

        if(take.score > skip.score) {
            ans = take;
        }
        else if(take.score < skip.score) {
            ans = skip;
        }
        else {
            if(smaller(take.indices, skip.indices))
                ans = take;
            else
                ans = skip;
        }

        return memo[i][k] = ans;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {

        n = intervals.size();

        // Add original index
        vector<vector<int>> arr;

        for(int i = 0; i < n; i++) {

            arr.push_back({
                intervals[i][0], // start
                intervals[i][1], // end
                intervals[i][2], // weight
                i                 // original index
            });
        }

        // Sort by starting position
        sort(arr.begin(), arr.end());

        memo.resize(n, vector<State>(5));
        vis.assign(n, vector<bool>(5, false));

        State ans = dfs(0, 4, arr);

        return ans.indices;
    }
};