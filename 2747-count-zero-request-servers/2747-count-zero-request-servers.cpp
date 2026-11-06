#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int num_queries = queries.size();
        int num_logs = logs.size();
        
        // Step 1: Sort the logs based on timestamp (logs[i][1])
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        // Step 2: Store queries with their original index to process "Offline"
        // Pair structure: {query_time, original_index}
        vector<pair<int, int>> sorted_queries(num_queries);
        for (int i = 0; i < num_queries; ++i) {
            sorted_queries[i] = {queries[i], i};
        }
        // Sort queries chronologically by time
        sort(sorted_queries.begin(), sorted_queries.end());
        
        // Step 3: Initialize sliding window variables
        vector<int> ans(num_queries);
        vector<int> server_counts(n + 1, 0); // Flat array for O(1) frequency lookups
        int unique_active_servers = 0;       // Counts unique servers hit in current window
        
        int left = 0;
        int right = 0;
        
        // Step 4: Run the sliding window over sorted queries
        for (int i = 0; i < num_queries; ++i) {
            int query_time = sorted_queries[i].first;
            int original_idx = sorted_queries[i].second;
            
            int window_start = query_time - x;
            int window_end = query_time;
            
            // Expand Window: Include logs that fall inside [..., window_end]
            while (right < num_logs && logs[right][1] <= window_end) {
                int server_id = logs[right][0];
                if (server_counts[server_id] == 0) {
                    unique_active_servers++; // Brand new server activated
                }
                server_counts[server_id]++;
                right++;
            }
            
            // Shrink Window: Exclude logs that fall out strictly before window_start
            while (left < num_logs && logs[left][1] < window_start) {
                int server_id = logs[left][0];
                server_counts[server_id]--;
                if (server_counts[server_id] == 0) {
                    unique_active_servers--; // Server completely lost all requests in window
                }
                left++;
            }
            
            // Store the result back into its original index position
            ans[original_idx] = n - unique_active_servers;
        }
        
        return ans;
    }
};
