class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long maxi = -1e17, mini = 1e17, n = nums.size();

        vector<int> maxele(n), minele(n);
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(maxi, nums[i]* 1LL);
            mini = min(mini, nums[i]* 1LL);

            maxele[i] = maxi;
            minele[i] = mini;
        }

        long long ans = -1e17;

        for (int i = n - m; i >= 0; i--) {
            long long val = 1LL * nums[i] * maxele[i + m - 1];
            val = max(val, 1LL * nums[i] * minele[i + m - 1]);
            ans = max(ans, val);
        }

        return ans;
    }
};