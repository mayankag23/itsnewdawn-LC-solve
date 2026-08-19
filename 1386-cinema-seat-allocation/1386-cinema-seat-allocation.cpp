class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> vis;

        for (auto &it : reservedSeats) {
            int row = it[0];
            int col = it[1];

            if (vis.find(row) == vis.end()) {
                vis[row] = vector<int>(11, 0);
            }

            vis[row][col] = 1;
        }

        long long cnt = 2 * (n - vis.size());

        for (auto &[row, seats] : vis) {

            bool left = (seats[2] == 0 &&
                         seats[3] == 0 &&
                         seats[4] == 0 &&
                         seats[5] == 0);

            bool middle = (seats[4] == 0 &&
                           seats[5] == 0 &&
                           seats[6] == 0 &&
                           seats[7] == 0);

            bool right = (seats[6] == 0 &&
                          seats[7] == 0 &&
                          seats[8] == 0 &&
                          seats[9] == 0);

            if (left && right) {
                cnt += 2;
            }
            else if (left || middle || right) {
                cnt += 1;
            }
        }

        return cnt;
    }
};