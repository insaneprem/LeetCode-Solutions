#include <vector>
#include <algorithm>

class Solution {
public:
    int maxFrequency(std::vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        long long sum = 0;  // Use long long to avoid integer overflow

        for (int i = 0, j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while ((long long)nums[j] * (j - i + 1) - sum > k) {
                sum -= nums[i];
                i++;
            }

            res = std::max(res, j - i + 1);
        }

        return res;
    }
};
