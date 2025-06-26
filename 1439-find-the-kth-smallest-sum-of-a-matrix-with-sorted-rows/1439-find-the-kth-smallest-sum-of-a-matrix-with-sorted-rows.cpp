class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m));

        for (int j = 0; j < m; j++) {
            dp[0][j].push_back(mat[0][j]);
        }

        vector<int> prev = mat[0];
        for (int i = 1; i < n; i++) {
            vector<int> curr;
            for (auto val : prev) {
                for (auto p : mat[i]) {
                    curr.push_back(val + p);
                }
            }

            sort(curr.begin(), curr.end());
            if (curr.size() > k)
                curr.resize(k);
            prev = curr;
        }

        vector<int> allsums;
        for (int j = 0; j < m; j++) {
            for (auto val : dp[n - 1][j]) {
                allsums.push_back(val);
            }
        }

        sort(allsums.begin(), allsums.end());
        return prev[k - 1];
    }
};
