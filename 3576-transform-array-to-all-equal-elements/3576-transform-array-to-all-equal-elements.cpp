class Solution {
public:
    int solve(vector<int> nums, int target, int k) {
        int n = nums.size(), op = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i] != target) {
                op++;
                nums[i] *= -1, nums[i + 1] *= -1;
            }
        }

        return nums.back() == nums[0] && op <= k;
    }
    bool canMakeEqual(vector<int>& nums, int k) {
        return solve(nums, 1, k) || solve(nums, -1, k);
    }
};