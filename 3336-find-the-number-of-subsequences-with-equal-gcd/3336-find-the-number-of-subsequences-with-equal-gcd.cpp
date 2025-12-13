class Solution {
public:
    const int MOD = 1e9 + 7;
    int dp[201][201][201];
    int solve(int idx, int gcd1, int gcd2, vector<int>& nums) {
        if (idx >= nums.size())
            return gcd1 == gcd2 && gcd1 > 0;

        if (dp[idx][gcd1][gcd2] != -1)
            return dp[idx][gcd1][gcd2] % MOD;
        int op1 = solve(idx + 1, __gcd(gcd1, nums[idx]), gcd2, nums) % MOD;
        int op2 = solve(idx + 1, gcd1, __gcd(gcd2, nums[idx]), nums) % MOD;
        int op3 = solve(idx + 1, gcd1, gcd2, nums) % MOD;
        
        // int ans = 
        return dp[idx][gcd1][gcd2] = (1LL * op1 + op2 + op3) % MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};