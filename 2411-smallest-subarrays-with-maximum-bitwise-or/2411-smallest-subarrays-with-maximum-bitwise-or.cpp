class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> bits(32);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j))
                    bits[j].push_back(i);
            }
        }

        vector<int> res;

        for (int i = 0; i < n; i++) {
            int farthest_idx = i;

            for (int j = 0; j < 32; j++) {
                if (nums[i] & (1 << j)) {
                    continue;
                }
                else {
                    auto it = lower_bound(begin(bits[j]), end(bits[j]), i);
                    if (it != bits[j].end()) {
                       farthest_idx = max(farthest_idx, *it);
                    }
                }
            }
            res.push_back(farthest_idx - i + 1);
        }

        return res;
    }
};