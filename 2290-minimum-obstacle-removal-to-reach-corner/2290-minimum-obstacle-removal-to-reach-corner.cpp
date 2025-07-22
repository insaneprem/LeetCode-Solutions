class Solution {
public:
    typedef pair<int, int> P;
    typedef pair<int, P> T;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dijkstra(int n, int m, vector<vector<int>>& grid,
                  vector<vector<int>>& dist) {
        dist[0][0] = 0;
        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [dist_so_far, cell] = pq.top();
            pq.pop();

            int x = cell.first, y = cell.second;

            if (dist_so_far > dist[x][y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = x + dirs[i][0];
                int ny = y + dirs[i][1];

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    dist[nx][ny] > dist_so_far + grid[nx][ny]) {
                    dist[nx][ny] = dist_so_far + grid[nx][ny];
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dijkstra(n, m, grid, dist);

        return dist[n - 1][m - 1];
    }
};