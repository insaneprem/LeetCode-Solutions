class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        vector<int> prefix_max(n), suffix_max(n);
        vector<int> prefix_min(n), suffix_min(n);

        prefix_max[0] = nums[0], prefix_min[0] = nums[0],
        suffix_max[n - 1] = nums.back(), suffix_min[n - 1] = nums.back();

        for (int i = 1; i < n; i++) {
            prefix_max[i] = max(prefix_max[i - 1], nums[i]);
            prefix_min[i] = min(prefix_min[i - 1], nums[i]);
        }

        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], nums[i]);
            suffix_min[i] = min(suffix_min[i + 1], nums[i]);
        }

        long long ans = -1e18;

        for (int i = 0; i + m - 1 < n; i++) {
            long long val1 = 1LL * prefix_max[i] * suffix_max[i + m - 1];
            long long val2 = 1LL * prefix_min[i] * suffix_min[i + m - 1];

            ans = max({val1, val2, ans});
        }

        return ans;
    }
};