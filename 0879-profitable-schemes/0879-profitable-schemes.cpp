class Solution {
public:
    const int MOD = 1e9 + 7;
    int n, minProfit;
    vector<int> group, profit;
    int dp[101][101][101];

    int solve(int idx, int peopleUsed, int currProfit) {
        if (peopleUsed > n)
            return 0;
        if (idx == group.size())
            return currProfit >= minProfit ? 1 : 0;

        if (dp[idx][peopleUsed][currProfit] != -1)
            return dp[idx][peopleUsed][currProfit];

        int ways = solve(idx + 1, peopleUsed, currProfit);

        int newPeople = peopleUsed + group[idx];
        int newProfit = min(minProfit,currProfit + profit[idx]);
        ways = (ways + solve(idx + 1, newPeople, newProfit)) % MOD;

        return dp[idx][peopleUsed][currProfit] = ways;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group,
                          vector<int>& profit) {
        this->n = n;
        this->minProfit = minProfit;
        this->group = group;
        this->profit = profit;

        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
