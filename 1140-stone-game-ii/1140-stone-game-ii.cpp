class Solution {
public:
    int dp[101][201][2];
    int solve(int idx, int m, int n, int turn, vector<int>& piles) {
        if (idx >= n)
            return 0;
        
        if(dp[idx][m][turn] != - 1) return dp[idx][m][turn];
        int ans = 0;
        if (turn) {
            int sum = 0;
            ans = -1e9;
            for (int i = 1; i <= 2 * m && idx + i <= n; i++) {
                sum += piles[idx + i - 1];
                ans = max(ans, sum + solve(idx + i, max(m, i), n, 0, piles));
            }
        } else { 
            ans = 1e9;
            for (int i = 1; i <= 2 * m && idx + i <= n; i++) {
                ans = min(ans, solve(idx + i, max(m, i), n, 1, piles));
            }
        }

        return dp[idx][m][turn] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(0, 1, piles.size(), 1, piles);
    }
};