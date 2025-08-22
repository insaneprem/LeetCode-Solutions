class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();

        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (!fresh) {
            return 0;
        }

        int time = 0;
        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {

                auto [r, c] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];

                    if ((nr >= 0 && nc >= 0 && nr < n && nc < m) &&
                        grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                }
            }
            time += (!q.empty());
        }
        return fresh == 0 ? time : -1;
    }
};