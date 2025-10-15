class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;
        }

        for (int i = 0; i + k < n; i++) {
            if (dp[i] >= k && dp[i + k] >= k)
                return true;
        }

        return false;
    }
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        int l = 0, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;

            if (check(nums, mid))
                l = mid + 1;
            else
                r = mid - 1;
        }

        return r;
    }
};