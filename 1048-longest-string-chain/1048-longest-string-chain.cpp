class Solution {
public:
    bool check(string small, string big) {
        int cnt = 0;
        int s = 0, b = 0;

        while (b < big.size()) {
            // aba
            // aaba
            if (small[s] == big[b])
                s++, b++;
            else
                cnt++, b++;
        }

        return cnt == 1;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();

        vector<int> dp(n, 1);
        int ans = 1;
        sort(begin(words),end(words),[](auto a,auto b){
            return a.size()<b.size();
        });

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].size() == words[j].size() + 1) {
                    if (check(words[j], words[i]))
                        dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};