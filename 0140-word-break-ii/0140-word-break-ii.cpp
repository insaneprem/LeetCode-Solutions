class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<string>> dp(n+1);
        set<string> st(begin(wordDict), end(wordDict));
        dp[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string sub = s.substr(j, i - j);
                if (st.count(sub) && !dp[j].empty()) {

                    for (auto str : dp[j]) {
                        if (str.empty())
                            dp[i].push_back(sub);
                        else
                            dp[i].push_back(str + " " + sub);
                    }
                }
            }
        }

        return dp[n];
    }
};