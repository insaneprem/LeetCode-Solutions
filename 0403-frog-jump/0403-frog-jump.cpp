class Solution {
public:
    map<int, int> mpp;
    int n;
    int dp[2001][2001];
    bool solve(int curr_stone_idx, int prevjump, vector<int>& stones) {
        if (curr_stone_idx == n - 1)
            return 1;
        
        if(dp[curr_stone_idx][prevjump] != -1) return dp[curr_stone_idx][prevjump];


        bool result = false;
        for (int curr_jump = prevjump - 1; curr_jump <= prevjump + 1;
             curr_jump++) {
            if (curr_jump > 0) {
                int next_stone = stones[curr_stone_idx] + curr_jump;

                if (mpp.find(next_stone) != mpp.end())
                    result =
                        result || solve(mpp[next_stone], curr_jump, stones);
            }
        }

        return dp[curr_stone_idx][prevjump]=result;
    }
    bool canCross(vector<int>& stones) {
        n = stones.size();
        for (int i = 0; i < n; i++)
            mpp[stones[i]] = i;
        
        memset(dp,-1,sizeof(dp));
        return solve(0, 0, stones);
    }
};