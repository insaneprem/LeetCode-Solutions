class Solution {
public:
    bool isvowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    int beautifulSubstrings(string s, int k) {
        int n = s.size(), ans = 0;

        vector<int> prefix(s.size() + 1, 0);

        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (isvowel(s[i - 1]));
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                int vowel = prefix[j] - prefix[i - 1];
                int consonants = j - i + 1 - vowel;

                if (vowel == consonants && (vowel * consonants) % k == 0)
                    ans++;
            }
        }

        return ans;
    }
};