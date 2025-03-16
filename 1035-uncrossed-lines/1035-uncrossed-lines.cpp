class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j,
              vector<vector<int>>& dp) {
        if (i >= nums1.size() || j >= nums2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int not_take = max(solve(nums1, nums2, i + 1, j, dp),
                           solve(nums1, nums2, i, j + 1, dp));
        int take = 0;
        if (nums1[i] == nums2[j])
            take = 1 + solve(nums1, nums2, i + 1, j + 1, dp);
        return dp[i][j] = max(take, not_take);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(), -1));
        return solve(nums1, nums2, 0, 0, dp);
    }
};