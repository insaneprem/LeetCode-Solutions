class Solution {
public:
    int ans = 0, n;
    string s;
    void check(int i, int j) {
        while (i >= 0 && j < n && s[i] == s[j]) {
            ans++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        this->s = s;
        n = s.size();
        for (int i = 0; i < n; i++) {
            check(i, i + 1);
            check(i, i);
        }

        return ans;
    }
};