class Solution {
public:
    int n, k;
    vector<int> nums;
    map<int, int> dp;
    const int MOD = 1e9 + 7;
    int solve(int i) {
        if (i == n)
            return 1;

        if (dp.find(i) != dp.end())
            return dp[i];

        int ans = 0;
        int mini = nums[i], maxi = nums[i];

        for (int j = i; j < n; j++) {
            maxi = max(maxi, nums[j]);
            mini = min(mini, nums[j]);

            if (maxi - mini > k)
                break;

            ans = (ans + solve(j + 1)) % MOD;
        }

        return dp[i] = ans;
    }
    int countPartitions(vector<int>& nums, int k) {
        this->nums = nums;
        this->k = k;
        this->n = nums.size();

        return solve(0);
    }
};