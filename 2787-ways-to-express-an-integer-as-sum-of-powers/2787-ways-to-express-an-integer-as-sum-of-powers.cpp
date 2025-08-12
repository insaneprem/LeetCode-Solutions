class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(int n, int x) {
        vector<int> arr;
        for (int i = 1; (int)pow(i, x) <= n; i++) {
            arr.push_back((int)pow(i, x));
        }

        for (auto i : arr)
            cout << i << " ";

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (auto num : arr) {
            for (int sum = n; sum >= num; sum--) {
                dp[sum] = (dp[sum] +  dp[sum - num]) % MOD;
            }
        }
        cout<<endl;

        for(auto i:dp) cout<<i<<" ";
        return dp[n];

        return 0;
    }
};