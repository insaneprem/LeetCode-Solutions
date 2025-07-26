class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k,
                              vector<vector<int>>& edges) {
        long long ans = 0, diff = 1e9;
        int cnt = 0;
        for (auto val : nums) {
            if ((val ^ k) > val) {
                ans += val ^ k;
                diff = min(diff, 1LL * ((val ^ k) - val));
                cnt++;
            } else {
                ans += val;
                diff = min(diff, 1LL * (val - (val ^ k)));
            }
        }

        if (cnt % 2 == 0)
            return ans;

        return ans - diff;
    }
};