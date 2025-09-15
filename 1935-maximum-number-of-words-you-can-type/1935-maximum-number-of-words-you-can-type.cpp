class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss(text);
        string token;

        vector<int> masks;

        int mask = 0;
        while (ss >> token) {
            mask = 0;
            for (auto &i : token)
                mask |= (1 << (i - 'a'));
            masks.push_back(mask);
        }

        mask = 0;
        for (auto &i : brokenLetters) mask |= (1 << (i - 'a'));

        int ans = 0;

        for (auto &m : masks) {
            ans += ((mask & m) == 0);
        }

        return ans;
    }
};