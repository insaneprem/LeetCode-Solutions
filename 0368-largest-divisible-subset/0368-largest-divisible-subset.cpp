class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
       

        ranges::sort(nums);
        vector<pair<int, int>> dp(n, {1, -1}); 

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[j].first + 1 > dp[i].first) {
                    dp[i].first = dp[j].first + 1;
                    dp[i].second = j;
                }
            }
        }

        int maxi = 0;
        for (int i = 1; i < n; i++) {
            if (dp[i].first > dp[maxi].first) {
                maxi = i;
            }
        }

        vector<int> ans;
        while (maxi != -1) {
            ans.push_back(nums[maxi]);
            maxi = dp[maxi].second;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
