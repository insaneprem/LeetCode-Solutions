class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        ranges::sort(nums);

        for (int i = 0; i + 1 < nums.size(); i++) {
            for (int k = nums[i] + 1; k <= nums[i + 1] - 1; k++)
                ans.push_back(k);
        }

        return ans;
    }
};