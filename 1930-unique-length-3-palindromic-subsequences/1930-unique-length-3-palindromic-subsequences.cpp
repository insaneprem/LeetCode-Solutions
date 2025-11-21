class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<vector<bool>> prefix(n, vector<bool>(26, 0)),
            suffix(n, vector<bool>(26, 0));

        for (int i = 0; i < n; i++) {
            char pch = s[i];
            char sch = s[n - i - 1];

            if (i > 0) {
                for (int j = 0; j < 26; j++) {
                   prefix[i][j] = prefix[i - 1][j];
                   suffix[n - i - 1][j] = suffix[n - i][j];
                }
            }
            prefix[i][pch - 'a'] = 1;
            suffix[n - i - 1][sch - 'a'] = 1;
        }

        unordered_set<string> st;

        for (int i = 1; i + 1 < n; i++) {
            for (int j = 0; j < 26; j++) {
                if (prefix[i - 1][j] && suffix[i + 1][j]) {
                    char ch = j + 'a';
                    string str = string() + ch + s[i] + ch;
                    st.insert(str);
                }
            }
        }

        return st.size();
    }
};