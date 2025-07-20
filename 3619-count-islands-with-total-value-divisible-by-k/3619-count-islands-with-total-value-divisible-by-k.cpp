class Solution {
public:
    int n, m;
    int dirs[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool isValid(int i, int j) { return !(i >= n || i < 0 || j >= m || j < 0); }
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if (!isValid(i, j))
            return 0;
        long long ans = grid[i][j];
        grid[i][j] = 0;

        for (int k = 0; k < 4; k++) {
            int ni = i + dirs[k][0];
            int nj = j + dirs[k][1];

            if (isValid(ni, nj) && grid[ni][nj] != 0) {
                ans += dfs(ni, nj, grid);
            }
        }

        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        this->n = grid.size();
        this->m = grid[0].size();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0)
                    if (dfs(i, j, grid) % k == 0)
                        ans++;
            }
        }
        return ans;
    }
};