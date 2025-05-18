class Solution { 
public:
    int memo[1000][1024] = {};
    int m, n, MOD = 1e9 + 7;
    int colorTheGrid(int m, int n) {
        this->m = m; this->n = n;
        return dp(0, 0, 0, 0);
    }
    int dp(int c, int prevColMask, int r, int curColMask) {
        if (c == n) return 1; 
        if (r == 0 && memo[c][prevColMask]) return memo[c][prevColMask];
        if (r == m) return dp(c + 1, curColMask, 0, 0);
        int ans = 0;
        for (int i = 1; i <= 3; i++) 
            if (getColor(prevColMask, r) != i && (r == 0 || getColor(curColMask, r-1) != i))
                ans = (ans + dp(c, prevColMask, r + 1, setColor(curColMask, r, i))) % MOD;
        if (r == 0) memo[c][prevColMask] = ans;
        return ans;
    }
    int getColor(int mask, int pos) { 
        return (mask >> (2 * pos)) & 3;
    }
    int setColor(int mask, int pos, int color) { 
        return mask | (color << (2 * pos));
    }
};