class Solution {
public:
    int n, m;
    int dirs[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    bool isValid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; }
    int shortestPath(vector<vector<int>>& grid, int k) {
        n = grid.size(), m = grid[0].size();

        vector<vector<vector<int>>> visited(
            n, vector<vector<int>>(m, vector<int>(k + 1, 0)));

        queue<tuple<int, int, int>> q;
        q.push({0, 0, k});
        visited[0][0][k] = 1;
        int Steps = 0;
        while (!q.empty()) {
            int qsize = q.size();

            while (qsize--) {

                auto [i, j, rem_obs] = q.front();
                q.pop();

                if(i == n-1 && j == m-1) return Steps;

                for (int d = 0; d < 4; d++) {
                    int ni = i + dirs[d][0];
                    int nj = j + dirs[d][1];

                    if (isValid(ni, nj) && grid[ni][nj] == 0 &&
                        !visited[ni][nj][rem_obs]) {
                        visited[ni][nj][rem_obs] = 1;
                        q.push({ni, nj, rem_obs});
                    } else if (isValid(ni, nj) && grid[ni][nj] == 1 &&
                               rem_obs > 0 && !visited[ni][nj][rem_obs - 1]) {
                        q.push({ni, nj, rem_obs - 1});
                        visited[ni][nj][rem_obs - 1] = 1;
                    }
                }

            }

            Steps++;
        }

        return -1;
    }
};