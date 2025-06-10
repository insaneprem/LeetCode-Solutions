class Solution {
public:
    int N, M, K;
    int dp[51][101][51];
    const int MOD = 1e9 + 7;
    int solve(int idx, int maxSofar, int searchCost) {
        if (idx == N)
            return searchCost == K;

        if (dp[idx][maxSofar][searchCost] != -1)
            return dp[idx][maxSofar][searchCost];

        int res = 0;

        for (int i = 1; i <= M; i++) {
            if (i > maxSofar)
                res = (res + solve(idx + 1, i, searchCost + 1)) % MOD;
            else
                res = (res + solve(idx + 1, maxSofar, searchCost)) % MOD;
        }

        return dp[idx][maxSofar][searchCost] = res;
    }
    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(dp, -1, sizeof(dp));

        return solve(0, 0, 0);
    }
};