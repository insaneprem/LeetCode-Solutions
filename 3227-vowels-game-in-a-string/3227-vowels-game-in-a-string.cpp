class Solution {
public:
    bool doesAliceWin(string s) {
        int ans = accumulate(begin(s), end(s), 0, [](int acc, char ch) {
            return acc + (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||
                          ch == 'u');
        });

        return ans != 0;
    }
};