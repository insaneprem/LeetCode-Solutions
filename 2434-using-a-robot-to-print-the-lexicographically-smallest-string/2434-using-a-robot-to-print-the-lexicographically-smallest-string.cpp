class Solution {
public:
    string robotWithString(string s) {
        map<char, int> cnt;
        for (auto ch : s) cnt[ch]++;
        
        stack<char> str;
        string res;
        char minCharacter = 'a';
        for (auto ch : s) {
            str.emplace(ch);
            cnt[ch]--;
            while (minCharacter != 'z' && cnt[minCharacter] == 0) {
                minCharacter++;
            }
            while (!str.empty() && str.top() <= minCharacter) {
                res.push_back(str.top());
                str.pop();
            }
        }

        return res;
    }
};