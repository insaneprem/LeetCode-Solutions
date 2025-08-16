class Solution {
public:
    const int MOD = 1e9 + 7;
    int modexp(int base, int exp) {
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
    int sumSubseqWidths(vector<int>& nums) {
        int ans = 0, n = nums.size();
        sort(begin(nums),end(nums));

        for (int i = 0; i < n; i++) {
            long long toadd = (1LL * nums[(n - i - 1)] * (modexp(2, n - i - 1) - 1)) % MOD;
            long long todel = (1LL * nums[i] * (modexp(2, n - i - 1) - 1)) % MOD;
            ans = (ans + toadd - todel + MOD) % MOD; 
        }

        return ans;
        return 0;
    }
};