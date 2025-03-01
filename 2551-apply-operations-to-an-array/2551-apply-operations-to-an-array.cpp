class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        vector<int> ans;
        for (int i = 0; i + 1 < n; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
            if (nums[i] > 0) ans.push_back(nums[i]);
            else cnt++;
        }
        ans.push_back(nums[n - 1]);

        for (int i = 0; i < cnt; i++) ans.push_back(0);
        return ans;
    }
};