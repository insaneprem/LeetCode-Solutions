class Solution {
public:
    int dp[501][501][2];
    int solve(int l, int r, int turn, vector<int>& piles) {
        if (r < l)
            return 0;
        if(dp[l][r][turn] != -1) return dp[l][r][turn]; 
        int ans;
        if (turn) {
            ans = -1e9;

            int op1 = piles[l] + solve(l + 1, r, 0, piles);
            int op2 = piles[r] + solve(l, r - 1, 0, piles);

            ans = max(op1, op2);
        } else {
            ans = 1e9;

            int op1 = piles[l] + solve(l + 1, r, 0, piles);
            int op2 = piles[r] + solve(l, r - 1, 0, piles);

            ans = min(op1, op2);
        }

        return dp[l][r][turn] = ans;
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(0 , piles.size() - 1 , 1 , piles);
    }
};