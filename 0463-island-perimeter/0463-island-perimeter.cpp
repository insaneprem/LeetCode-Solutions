class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int islandPerimeter(vector<vector<int>>& grid) {

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    int val = 0;
                    for (int d = 0; d < 4; d++) {
                        int ni = i + dirs[d][0];
                        int nj = j + dirs[d][1];

                        if (ni >= 0 && ni < grid.size() && nj >= 0 &&
                            nj < grid[0].size() && grid[ni][nj] == 1) {
                            val++;
                        }
                    }
                    ans += 4 - val;
                }
            }
        }

        return ans;
    }
};