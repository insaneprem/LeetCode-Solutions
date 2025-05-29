class Solution {
public:
    int n, k;
    static const int MOD = 1e9 + 7;
    int dp[101][101][101];

    int mod_exp(int a, int b, int mod = MOD) {
        int res = 1;
        a %= mod;

        while (b > 0) {
            if (b & 1)
                res = (1LL * res * a) % mod;
            a = (1LL * a * a) % mod;
            b >>= 1;
        }

        return res;
    }

    int solve(int idx, int sum, int takencnt, vector<int>& nums) {
        if (sum > k)
            return 0;
        if (idx == n) {
            return sum == k ? mod_exp(2, n - takencnt) : 0;
        }

        if (dp[idx][sum][takencnt] != -1)
            return dp[idx][sum][takencnt];

        int take = solve(idx + 1, sum + nums[idx], takencnt + 1, nums);
        int ntake = solve(idx + 1, sum, takencnt, nums);

        return dp[idx][sum][takencnt] = (take + ntake) % MOD;
    }

    int sumOfPower(vector<int>& nums, int k) {
        this->n = nums.size();
        this->k = k;

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};
