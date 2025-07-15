class Solution {
public:
    bool isvowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') ||
        (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') ;
    }
    bool ischar(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
    bool isValid(string word) {
        bool ans = word.size() > 2;
        int v = 0, c = 0;
        for (auto ch : word) {
            if (isvowel(ch))
                v++;
            else if (ischar(ch))
                c++;
            else if (!(ch >= '0' && ch <= '9'))
                return false;
        }

        return v > 0 && c > 0 && ans;
    }
};