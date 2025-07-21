class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = string(1, s[0]);

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == s[i - 1] && s[i] == s[i + 1])
                continue;
            else
                ans += s[i];
        }

        if (n > 1) ans += s[n - 1];
        
        return ans;
    }
};