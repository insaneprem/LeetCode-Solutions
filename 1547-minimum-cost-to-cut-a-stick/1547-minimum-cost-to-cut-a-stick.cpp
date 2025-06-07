class Solution {
public:
    int n;
    vector<int> cuts;
    int dp[107][107];
    int solve(int l, int r) {
        if (r - l < 2)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];
        int result = INT_MAX;
        for (int idx = l + 1; idx <= r - 1; idx++) {
            result = min(result,
                         (cuts[r] - cuts[l]) + solve(l, idx) + solve(idx, r));
        }

        return dp[l][r] = result;
    }
    int minCost(int n, vector<int>& cuts) {
        this->n = n;
        cuts.push_back(0);
        cuts.push_back(n);
        sort(begin(cuts), end(cuts));
        this->cuts = cuts;
        memset(dp, -1, sizeof(dp));
        cout<<cuts.size();
        return solve(0, cuts.size() - 1);
    }
};