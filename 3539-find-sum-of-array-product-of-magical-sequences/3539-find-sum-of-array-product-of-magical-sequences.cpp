class Solution {
public:
    const int mod = 1e9 + 7;

    int add(int a, int b) { return (a + b) % mod; }
    int mul(int a, int b) { return 1LL * a * b % mod; }

    int modpow(int a, int b) {
        int res = 1;
        while (b) {
            if (b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        int n = nums.size();
        vector<int> fact(m + 1, 1), invf(m + 1, 1);
        for (int i = 1; i <= m; i++) fact[i] = mul(fact[i - 1], i);
        invf[m] = modpow(fact[m], mod - 2);
        for (int i = m - 1; i >= 0; i--) invf[i] = mul(invf[i + 1], i + 1);

        vector<vector<int>> pow_nums(n, vector<int>(m + 1, 1));
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= m; j++)
                pow_nums[i][j] = mul(pow_nums[i][j - 1], nums[i]);

        int h = n + 6;
        vector dp(2, vector(m + 1, vector(k + 1, vector<int>(m + 1))));
        dp[0][0][0][0] = 1;

        for (int i = 0; i < h; i++) {
            dp[1] = vector(m + 1, vector(k + 1, vector<int>(m + 1, 0)));
            for (int used = 0; used <= m; used++) {
                for (int pop = 0; pop <= k; pop++) {
                    for (int carry = 0; carry <= m; carry++) {
                        int val = dp[0][used][pop][carry];
                        if (!val) continue;
                        if (i < n) {
                            for (int cnt = 0; cnt + used <= m; cnt++) {
                                int sum = carry + cnt;
                                int bit = sum % 2, next_carry = sum / 2;
                                if (pop + bit > k) continue;
                                int w = mul(val, mul(pow_nums[i][cnt], invf[cnt]));
                                dp[1][used + cnt][pop + bit][next_carry] = add(dp[1][used + cnt][pop + bit][next_carry], w);
                            }
                        } else {
                            int bit = carry % 2, next_carry = carry / 2;
                            if (pop + bit <= k)
                                dp[1][used][pop + bit][next_carry] = add(dp[1][used][pop + bit][next_carry], val);
                        }
                    }
                }
            }
            swap(dp[0], dp[1]);
        }
        return mul(dp[0][m][k][0], fact[m]);
    }
};
