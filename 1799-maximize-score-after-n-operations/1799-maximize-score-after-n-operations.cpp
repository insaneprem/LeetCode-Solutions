class Solution {
public:
    int m, n;
    vector<int> nums;
    unordered_map<vector<bool>, int> dp;
    int solve(int op, vector<bool>& visited) {
        if (op > n)
            return 0;

        if (dp.find(visited) != dp.end())
            return dp[visited];

        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (visited[i])
                continue;
            for (int j = 0; j < m; j++) {
                if (visited[j] || i == j)
                    continue;

                int score = op * gcd(nums[i], nums[j]);
                visited[i] = 1;
                visited[j] = 1;

                ans = max(ans, score + solve(op + 1, visited));
                visited[i] = 0;
                visited[j] = 0;
            }
        }

        return dp[visited] = ans;
    }
    int maxScore(vector<int>& nums) {
        this->m = nums.size();
        this->n = nums.size() / 2;
        this->nums = nums;
        vector<bool> visited(m, 0);

        return solve(1, visited);
    }
};