class Solution {
public:
    vector<string> stringSequence(string target) {

        string s = "a";
        vector<string> ans = {s};

        int n = target.size();
        for (int i = 1; i <= n; i++) {
            string prefix = target.substr(0, i);
            
            while (s.size() < prefix.size()) {
                s.push_back('a');
                ans.push_back(s);
            }
            while (s != prefix) {
                (s.back() == 'z') ? s.back() = 'a' : s.back() = s.back() + 1;
                ans.push_back(s);
            }
        }
        return ans;
    }
};
