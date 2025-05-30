class Solution {
public:
    map<int, int> dp;
    int m, n;
    vector<int> nums;
    int solve(int op, int mask) {
        if (op > n)
            return 0;

        if (dp.find(mask) != dp.end())
            return dp[mask];

        int maxscore = 0;
        for (int i = 0; i < m; i++) {
            if (mask & (1 << i))
                continue;
            for (int j = i + 1; j < m; j++) {
                if (mask & (1 << j))
                    continue;

                int newmask = (1 << i) | (1 << j) | mask;
                int score = op * gcd(nums[i], nums[j]) + solve(op + 1, newmask);

                maxscore = max(maxscore, score);
            }
        }

        return dp[mask] = maxscore;
    }
    int maxScore(vector<int>& nums) {
        this->nums = nums;
        this->m = nums.size();
        this->n = nums.size() / 2;

        return solve(1, 0);
    }
};