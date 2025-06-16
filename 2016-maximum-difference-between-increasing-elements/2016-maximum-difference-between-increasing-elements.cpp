class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size(), ans = -1, mini = nums[0];

        for (int i = 1; i < n; i++) {
            if (nums[i] > mini) {
                ans = max(ans, nums[i] - mini);
            } else {
                mini = nums[i];
            }
        }

        return ans;
    }
};