class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef tuple<int, int, int> T;
    int n, m;
    bool isValid(int i, int j) { return (i >= 0 && j >= 0 && i < n && j < m); }
    int minTimeToReach(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [distsofar, i, j] = pq.top();
            pq.pop();

            for (auto it : dir) {
                int ni = i + it.first;
                int nj = j + it.second;

                if (isValid(ni, nj)) {
                    int toadd = (ni + nj) % 2 ? 1 : 2;

                    int newdist = max(grid[ni][nj], distsofar) + toadd;

                    if (newdist < dp[ni][nj]) {
                        dp[ni][nj] = newdist;
                        pq.push({newdist, ni, nj});
                    }
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};