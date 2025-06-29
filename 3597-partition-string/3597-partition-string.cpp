class Solution {
public:
    vector<string> partitionString(string s) {
        set<string> seen;
        int n = s.size();

        string temp;
        vector<string> ans;
        for (auto ch : s) {
            temp += ch;
            if (!seen.count(temp)) {
                seen.insert(temp);
                ans.push_back(temp);
                temp = "";
            }
        }

        return ans;
    }
};