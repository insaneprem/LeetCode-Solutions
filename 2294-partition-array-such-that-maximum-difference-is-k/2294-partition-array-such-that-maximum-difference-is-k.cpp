class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size(), ans = 0;
        int mini = nums[0], maxi = nums[0];
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);

            if (maxi - mini > k) {
                ans++;
                maxi = nums[i];
                mini = nums[i];
            }
        }

        return ans + 1;
    }
};