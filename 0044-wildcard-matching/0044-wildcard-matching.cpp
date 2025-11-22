class Solution {
public:
    int dp[2001][2001];
    bool isChar(char ch) { return ch >= 'a' && ch <= 'z'; }
    bool solve(int idx1, int idx2, string& s, string& p) {
        if (idx1 >= s.size() && idx2 >= p.size())
            return true;
        if (idx2 >= p.size())
            return false;
        if (idx1 >= s.size()) {
            for (int i = idx2; i < p.size(); i++) {
                if (p[i] != '*')
                    return false;
            }

            return true;
        }

        if (dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        bool ismatch = true;

        if (isChar(p[idx2])) {
            ismatch &= s[idx1] == p[idx2];
            ismatch &= solve(idx1 + 1, idx2 + 1, s, p);
        } else if (p[idx2] == '?') {
            ismatch &= solve(idx1 + 1, idx2 + 1, s, p);
        } else {
            ismatch &= solve(idx1 + 1, idx2, s, p) ||
                       solve(idx1 + 1, idx2 + 1, s, p) ||
                       solve(idx1, idx2 + 1, s, p);
        }

        return dp[idx1][idx2] = ismatch;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, s, p);
    }
};