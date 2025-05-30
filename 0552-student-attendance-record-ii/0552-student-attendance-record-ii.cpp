class Solution {
public:
    int n;
    int dp[100002][2][3];
    const int MOD = 1e9 + 7;
    int solve(int day, int absentcnt, int clc) {
        if (clc > 2 || absentcnt > 1)
            return 0;
        if (day == n)
            return 1;

        if (dp[day][absentcnt][clc] != -1)
            return dp[day][absentcnt][clc];
        long long res = 0;

        res = (res + solve(day + 1, absentcnt, 0)) % MOD;
        res = (res + solve(day + 1, absentcnt + 1, 0)) % MOD;
        res = (res + solve(day + 1, absentcnt, clc + 1)) % MOD;

        return dp[day][absentcnt][clc] = res;
    }
    int checkRecord(int n) {
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};