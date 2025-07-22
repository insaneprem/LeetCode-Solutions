class Solution {
public:
    typedef tuple<int, int, int> T;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = grid[0][0];
        while (!pq.empty()) {
            auto [distsofar, x, y] = pq.top();
            pq.pop();

            if (distsofar > dist[x][y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                    if (distsofar + grid[nx][ny] < dist[nx][ny]) {
                        dist[nx][ny] = distsofar + grid[nx][ny];
                        pq.push({dist[nx][ny], nx, ny});
                    }
                }
            }
        }

        for (auto i : dist) {
            for (auto j : i)
                cout << j << " ";
            cout << endl;
        }

        return dist[n - 1][m - 1];
    }
};