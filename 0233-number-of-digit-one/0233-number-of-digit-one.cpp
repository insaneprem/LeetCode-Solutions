class Solution {
public:
    string num;
    int dp[32][2][32];
    int solve(int pos, int tight, int count) {
        if (pos == num.size())
            return count;

        if (dp[pos][tight][count] != -1)
            return dp[pos][tight][count];
        int ub = tight ? num[pos] - '0' : 9;

        int ans = 0;
        for (int dig = 0; dig <= ub; dig++) {
            ans = ans + solve(pos + 1, tight & (ub == dig), count + (dig == 1));
        }

        return dp[pos][tight][count] = ans;
    }
    int countDigitOne(int n) {
        num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0, 1, 0);
    }
};