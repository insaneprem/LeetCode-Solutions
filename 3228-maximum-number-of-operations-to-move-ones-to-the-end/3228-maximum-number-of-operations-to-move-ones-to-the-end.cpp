class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, onecnt = 0, n = s.size();

        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1')
                onecnt++;
            if (s[i] == '0' && s[i + 1] == '1')
                ans += onecnt;
        }

        if(s.back() == '0') ans+=onecnt;

        return ans;
    }
};