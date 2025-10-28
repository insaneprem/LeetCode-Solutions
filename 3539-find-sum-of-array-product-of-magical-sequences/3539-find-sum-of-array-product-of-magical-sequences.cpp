class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAXN = 31;
    int n;
    vector<int> fact, factinv;
    map<string,int> dp;
    int modpow(int base, int exp) {
        base %= MOD;
        long long ans = 1;
        while (exp) {
            if (exp & 1)
                ans = (ans * base) % MOD;
            base = (1LL * base * base) % MOD;
            exp >>= 1;
        }
        return ans;
    }

    int modinv(int val) { return modpow(val, MOD - 2); }

    void precomp() {
        fact.resize(MAXN);
        factinv.resize(MAXN);
        fact[0] = 1;
        for (int i = 1; i <= 30; i++)
            fact[i] = (1LL * fact[i - 1] * i) % MOD;
        factinv[30] = modinv(fact[30]);
        for (int i = 29; i >= 0; i--)
            factinv[i] = (1LL * factinv[i + 1] * (i + 1)) % MOD;
    }

    int ncr(int n, int r) {
        if (n < 0 || r < 0 || r > n)
            return 0;
        int ans = fact[n];
        ans = (1LL * ans * factinv[n - r]) % MOD;
        ans = (1LL * ans * factinv[r]) % MOD;
        return ans;
    }

    int solve(int idx, int bitsum, int m, int k, vector<int>& nums) {
        if (m == 0 && __builtin_popcount(bitsum) == k)
            return 1;

        if (m == 0 || idx >= n)
            return 0;
        
        auto key = to_string(idx) + '_' + to_string(bitsum) + '_' + to_string(m) + '_' + to_string(k);

        if(dp.count(key)) return  dp[key];

        int tsum = solve(idx + 1, (bitsum >> 1), m, k - (bitsum & 1), nums);

        for (int freq = 1; freq <= m; freq++) {
            int newsum = bitsum + freq;
            long long prod = modpow(nums[idx], freq) % MOD;
            long long ways = ncr(m, freq);

            prod = (prod * ways) % MOD;

            prod = (prod * solve(idx + 1, newsum >> 1, m - freq, k - (newsum & 1), nums)) % MOD;
            tsum = (tsum + prod) % MOD;
        }

        return dp[key] = tsum % MOD;
    }

    int magicalSum(int m, int k, vector<int>& nums) {
        this->n = nums.size();
        dp.clear();
        precomp();
        return solve(0, 0, m, k, nums);
    }
};
