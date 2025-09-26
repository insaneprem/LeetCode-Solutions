class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int ul = nums[i] + nums[j] - 1;
                int ll = abs(nums[i] - nums[j]) + 1;

                auto it = lower_bound(begin(nums) + j + 1, end(nums), ll);
                auto bt = upper_bound(begin(nums) + j + 1, end(nums), ul);

                bt--;
                if (it > bt)
                    continue;

                ans += distance(it, bt) + 1;
            }
        }
        return ans;
    }
};