class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));

        for (int i = 0; i <= m - k; i++) {
            for (int j = 0; j <= n - k; j++) {
                vector<int> elements;
                for (int r = i; r < i + k; r++) {
                    for (int c = j; c < j + k; c++) {
                        elements.push_back(grid[r][c]);
                    }
                }

                sort(begin(elements), end(elements));
                elements.erase(unique(elements.begin(), elements.end()),
                               elements.end());

                if (elements.size() == 1) {
                    ans[i][j] = 0;
                } else {
                    int minDiff = INT_MAX;
                    for (int x = 1; x < (int)elements.size(); x++) {
                        minDiff = min(minDiff, elements[x] - elements[x - 1]);
                    }
                    ans[i][j] = minDiff;
                }
            }
        }
        return ans;
    }
};