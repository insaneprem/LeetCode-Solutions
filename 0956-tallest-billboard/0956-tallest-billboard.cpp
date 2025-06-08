class Solution {
public:
    vector<int> rods;
    unordered_map<string, int> dp;
    int solve(int idx, int diff) {
        if (idx == rods.size())
            return (!diff) ? 0 : -1e9;

        string key = to_string(idx) + "_" + to_string(diff);
        if (dp.find(key) != dp.end())
            return dp[key];

        int ntake = solve(idx + 1, diff);
        int ltake = rods[idx] + solve(idx + 1, diff + rods[idx]);
        int rtake = rods[idx] + solve(idx + 1, diff - rods[idx]);

        return dp[key] = max({ntake, rtake, ltake});
    }
    int tallestBillboard(vector<int>& rods) {
        this->rods = rods;

        return solve(0, 0) / 2;
    }
};