class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, r = 0, n = s.size(), ans = 0;
        vector<int> freq(26, 0);
        while (r < n) {
            freq[s[r] - 'a']++;

            while (freq[s[r] - 'a'] > 2) {
                freq[s[l++] - 'a']--;
            }

            ans = max(ans, r - l + 1);
            r++;
        }

        return ans;
    }
};