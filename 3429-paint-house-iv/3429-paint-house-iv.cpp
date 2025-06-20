class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        int sz = n / 2;
        vector<vector<long long>> dp(sz, vector<long long>(6, 0));

        dp[0][0] = cost[0][0] + cost[n-1][1]; 
        dp[0][1] = cost[0][0] + cost[n-1][2]; 
        dp[0][2] = cost[0][1] + cost[n-1][0]; 
        dp[0][3] = cost[0][1] + cost[n-1][2]; 
        dp[0][4] = cost[0][2] + cost[n-1][0]; 
        dp[0][5] = cost[0][2] + cost[n-1][1]; 

        for (int i = 1; i < sz; i++ ){
            dp[i][0] = min({dp[i-1][2], dp[i-1][3], dp[i-1][4]}) + cost[i][0] + cost[n-i-1][1];
            dp[i][1] = min({dp[i-1][2], dp[i-1][4], dp[i-1][5]}) + cost[i][0] + cost[n-i-1][2];
            dp[i][2] = min({dp[i-1][0], dp[i-1][1], dp[i-1][5]}) + cost[i][1] + cost[n-i-1][0];
            dp[i][3] = min({dp[i-1][0], dp[i-1][4], dp[i-1][5]}) + cost[i][1] + cost[n-i-1][2];
            dp[i][4] = min({dp[i-1][0], dp[i-1][1], dp[i-1][3]}) + cost[i][2] + cost[n-i-1][0];
            dp[i][5] = min({dp[i-1][1], dp[i-1][2], dp[i-1][3]}) + cost[i][2] + cost[n-i-1][1];
        }

        return *min_element(dp[sz-1].begin(), dp[sz-1].end());
    }
};
