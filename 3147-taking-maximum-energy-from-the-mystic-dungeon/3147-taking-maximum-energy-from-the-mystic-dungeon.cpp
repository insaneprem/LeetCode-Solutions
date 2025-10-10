class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, -1e9);
        int ans = -1e9;
        for (int i = n - 1; i >= 0; i--) {
            int val = energy[i] + (i + k < n ? dp[i + k] : 0);
            dp[i] = val;
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};