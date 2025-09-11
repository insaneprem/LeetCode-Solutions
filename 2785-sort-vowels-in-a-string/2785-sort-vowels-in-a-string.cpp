class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](auto ch) {
            ch = tolower(ch);
            return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                    ch == 'u');
        };

        vector<char> vowels;
        for (auto i : s) {
            if (isVowel(i))
                vowels.push_back(i);
        }

        sort(begin(vowels), end(vowels));
        string ans = "";
        int idx = 0;
        for (auto i : s) {
            ans += (isVowel(i) ? vowels[idx++] : i);
        }
        return ans;
    }
};