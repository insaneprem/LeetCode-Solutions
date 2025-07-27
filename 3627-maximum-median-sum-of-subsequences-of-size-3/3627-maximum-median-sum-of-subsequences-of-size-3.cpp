class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        // 1 1 2 2 3 3

        long long ans = 0;
        int n = nums.size();
        int i = 0, j = n - 2;

        ranges::sort(nums);

        while (i < j) {
            ans += nums[j];
            i++;
            j -= 2;
        }

        return ans;
    }
};