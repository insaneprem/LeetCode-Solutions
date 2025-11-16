class Solution {
public:
    const int MOD = 1e9 + 7;
    int numSub(string s) {
        int n = s.size();

        int l = 0;
        int ans = 0;
        while (l < n) {
            if (s[l] == '0')
                l++;
            else {
                int prev = l;
                while (l < n && s[l] == '1')
                    l++;

                long long val = l - prev;
                ans = (ans + ((val * (val + 1)) / 2)) % MOD;
            }
        }

        return ans;
        ;
        ;
    }
};