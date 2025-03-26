class Solution {
public:
    int minMoves(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0, n = nums.size();

        for (int i = n - 1; i >= 0; i--) ans += nums[i] - nums[0];
        return ans;
        // return 0;
        // 15 16 22 15 14
        // 22 23 22 22 7
        // 22 22 23 22 1
    }
};