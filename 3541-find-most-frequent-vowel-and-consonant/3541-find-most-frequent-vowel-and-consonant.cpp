class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26);
        set<char> st({'a', 'e', 'i', 'o', 'u'});
        for (auto i : s) {
            freq[i - 'a']++;
        }

        int count = 0, vowel = 0;

        for (int i = 0; i < 26; i++) {
            if (st.count(i + 'a'))
                vowel = max(vowel, freq[i]);
            else
                count = max(count, freq[i]);
        }
        return count + vowel;
    }
};