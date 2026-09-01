class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Find starting position and number the L cells
        int sx = -1, sy = -1;
        int lamps = 0;

        vector<vector<int>> id(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }

                else if (classroom[i][j] == 'L') {
                    id[i][j] = (1 << lamps);
                    lamps++;
                }
            }
        }

        /*
        visited[x][y][mask]

        Stores maximum energy with which we have reached
        cell (x,y) after collecting the lamps represented by mask.
        */
        vector<vector<vector<int>>> visited(
            m,
            vector<vector<int>>(
                n,
                vector<int>(1 << lamps, -1)
            )
        );

        // {x, y, mask, currentEnergy, steps}
        queue<vector<int>> q;

        q.push({sx, sy, 0, energy, 0});
        visited[sx][sy][0] = energy;

        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};

        while (!q.empty()) {

            vector<int> curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int mask = curr[2];
            int currEnergy = curr[3];
            int steps = curr[4];

            // All L cells collected
            if (mask == (1 << lamps) - 1) {
                return steps;
            }

            // Cannot move further
            if (currEnergy == 0) {
                continue;
            }

            for (int i = 0; i < 4; i++) {

                int nx = x + dx[i];
                int ny = y + dy[i];

                // Check boundary
                if (nx < 0 || nx >= m ||
                    ny < 0 || ny >= n) {
                    continue;
                }

                // Cannot cross X
                if (classroom[nx][ny] == 'X') {
                    continue;
                }

                int newEnergy;

                // Recharge energy
                if (classroom[nx][ny] == 'R') {
                    newEnergy = energy;
                }
                else {
                    newEnergy = currEnergy - 1;
                }

                // Update collected L cells
                int newMask = mask | id[nx][ny];

                // If we reached this state with more energy
                if (newEnergy > visited[nx][ny][newMask]) {

                    visited[nx][ny][newMask] = newEnergy;

                    q.push({nx, ny, newMask, newEnergy, steps + 1});
                }
            }
        }

        return -1;
    }
};