class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1) return 0; 
        int ans = 1e9;
        ranges::sort(nums);
        
        for (int i = 0; i <= nums.size() - k; i++) {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        
        return ans;
    }
};
