class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int prev = nums[0] - k;
        int ans = 1;
        for (int i = 1; i < n; i++) {
            int val = prev + 1;

            if (abs(val - nums[i]) <= k)
                prev++, ans++;
            else if (nums[i] - k > prev)
                prev = nums[i] - k, ans++;
        }

        return ans;
    }
};