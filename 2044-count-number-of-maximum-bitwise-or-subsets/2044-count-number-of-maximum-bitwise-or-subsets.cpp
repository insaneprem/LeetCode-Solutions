class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        map<int, int> mp;
        for (int i = 0; i < (1 << n); i++) {
            int subsetOr = 0;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))
                    subsetOr |= nums[j];
            }
            mp[subsetOr]++;
        }

        return mp.rbegin()->second;
    }
};