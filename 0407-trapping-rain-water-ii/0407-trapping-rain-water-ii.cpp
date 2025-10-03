class Solution {
public:
    typedef pair<int, pair<int, int>> P;
    int n, m, ans;
    bool isValid(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int trapRainWater(vector<vector<int>>& heightMap) {
        n = heightMap.size();
        m = heightMap[0].size();
        ans = 0;

        priority_queue<P, vector<P>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    vis[i][j] = 1;
                    pq.push({-1 * heightMap[i][j], {i, j}});
                }
            }
        }

        while (!pq.empty()) {
            int height = (-1) * pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for (auto d : dir) {
                int ni = i + d.first, nj = j + d.second;
                if (isValid(ni, nj) && !vis[ni][nj]) {
                    vis[ni][nj]=1;
                    ans += max(0, height - heightMap[ni][nj]);
                    pq.push({(-1) * max(height, heightMap[ni][nj]), {ni, nj}});
                }
            }
        }

        return ans;
    }
};