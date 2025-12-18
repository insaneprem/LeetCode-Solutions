class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> prefix(n);
        prefix[0] = prices[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prices[i];
            prefix[i] += prefix[i - 1];
        }

        long long tsum = 0;

        for (int i = 0; i < n; i++) {
            tsum += prices[i] * strategy[i];
        }

        long long currsum = 0;
        long long ans = tsum;
        for (int i = 0; i < n; i++) {
            currsum += prices[i] * strategy[i];

            if (i >= k - 1) {
                long long val = tsum - currsum;
                val += prefix[i] - prefix[i - (k / 2)];
                ans = max(ans, val);
                currsum -= (prices[i - k + 1] * strategy[i - k + 1]);
            }
        }

        return ans;
    }
};