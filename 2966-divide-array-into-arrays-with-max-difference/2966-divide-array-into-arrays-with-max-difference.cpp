class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums), end(nums));

        vector<vector<int>> ans;
        for (int i = 1; i < n; i += 3) {
            if (nums[i + 1] - nums[i] > k || nums[i] - nums[i - 1] > k ||
                nums[i + 1] - nums[i - 1] > k)
                return {};
            else {

                ans.emplace_back(
                    vector<int>{nums[i - 1], nums[i], nums[i + 1]});
                cout << nums[i - 1] << " " << nums[i] << " " << nums[i + 1]
                     << "\n";
            }
        }

        return ans;
    }
};