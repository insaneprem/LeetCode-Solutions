class Solution {
public:
    vector<int> zero, one;
    int sz, N, M;
    int dp[607][107][107];
    int rec(int idx, int taken0, int taken1) {
        if (idx >= sz) {
            if (taken0 <= M && taken1 <= N)
                return 0;

            return INT_MIN;
        }

        if(taken0>M || taken1>N) return INT_MIN;

        if(dp[idx][taken0][taken1] != -1) return dp[idx][taken0][taken1];

        int val = rec(idx + 1, taken0, taken1);
        int tval = 1 + rec(idx + 1, taken0 + zero[idx], taken1 + one[idx]);

        return dp[idx][taken0][taken1] = max(val, tval);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        M = m;
        N = n;

        sz = strs.size();
        zero.resize(sz);
        one.resize(sz);

        for (int i = 0; i < sz; i++) {
            int z = count(begin(strs[i]), end(strs[i]), '0');
            zero[i] = z;
            one[i] = strs[i].size() - z;
        }

        memset(dp,-1,sizeof(dp));

        return rec(0, 0, 0);
    }
};