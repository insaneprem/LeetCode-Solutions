class Solution {
public:
    int k;
    int dp[1001][2001];
    int solve(int i, int k, vector<vector<int>>& piles) {
        if (i >= piles.size())
            return 0;

        if(dp[i][k] != -1) return dp[i][k];

        int ntake = solve(i + 1, k, piles);
        int taken = 0, sum = 0, res = 0;

        int total = piles[i].size();
        for (int j = 0; j < min(total, k); j++) {
            sum += piles[i][j];

            taken = max(taken, sum + solve(i + 1, k - (j + 1), piles));
        }

        return dp[i][k]=max(ntake, taken);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        this->k = k;
        memset(dp, -1, sizeof(dp));
        return solve(0, k, piles);
    }
};