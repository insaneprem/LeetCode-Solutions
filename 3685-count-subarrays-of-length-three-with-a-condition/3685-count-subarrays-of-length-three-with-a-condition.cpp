class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        for (int i = 1; i + 1 < n; i++) ans+=(nums[i-1]+nums[i+1])*2 == nums[i];

        return ans;
    }
};