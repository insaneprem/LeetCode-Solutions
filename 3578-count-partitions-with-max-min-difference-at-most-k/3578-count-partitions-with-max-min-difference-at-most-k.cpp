class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        const long long mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        vector<long long> prefix(n + 1);
        multiset<int> mst;
        dp[0] = 1;
        prefix[0] = 1;

        for (int i = 0, j = 0; i < nums.size(); i++) {
            mst.emplace(nums[i]);
            while (j <= i && *mst.rbegin() - *mst.begin() > k) {
                mst.erase(mst.find(nums[j]));
                j++;
            }
            dp[i + 1] = (prefix[i] - (j > 0 ? prefix[j - 1] : 0) + mod) % mod;
            prefix[i + 1] = (prefix[i] + dp[i + 1]) % mod;
        }
        return dp[n];
    }
};