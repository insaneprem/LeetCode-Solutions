class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        long long shift = accumulate(begin(shifts), end(shifts), 0LL);

        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            char ch = 'a' + (((s[i] - 'a') + (shift % 26)) % 26);
            ans+=ch;
            shift-=shifts[i];
        }
        
        return ans;
    }
};