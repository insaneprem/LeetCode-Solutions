class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int val = 0, n = nums.size(), sum = 0;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            val += i * nums[i];
        }

        int ans = val;

        int idx = n - 1;
        // cout<<ans;
        while (idx >= 1) {
            val -= (n - 1) * nums[idx];
            val += sum - nums[idx];
            idx--;
            ans = max(ans, val);
        }

        return ans;
    }
};