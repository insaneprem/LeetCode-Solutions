class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[100005][3];
    int solve(string& str, int idx, int currseat) {
        if (idx >= str.size())
            return currseat == 2;
        char ch = str[idx];
        int ans = 0;

        if(dp[idx][currseat] != -1) return dp[idx][currseat];
        if (ch == 'S') {
            if (currseat == 2) {
                ans = solve(str, idx + 1, 1) % MOD; 
            } else {
                ans = solve(str, idx + 1, currseat + 1) % MOD;
            }
        } else {
            if (currseat < 2)
                ans = solve(str, idx + 1, currseat) % MOD;
            else {
                int op1 = solve(str, idx + 1, currseat) % MOD;
                int op2 = solve(str, idx + 1, 0) % MOD;

                ans = (1LL * op1 + op2) % MOD;
            }
        }

        return dp[idx][currseat] = ans;
    }
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return solve(corridor, 0, 0);
    }
};