class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size();

        map<int, int> dp;
        int ans = 1;
        for (auto i : arr) {
            dp[i] = 1 + dp[i - difference];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};