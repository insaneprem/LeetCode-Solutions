class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mpp;

        for (auto it : strs) {
            string t = it;
            ranges::sort(t);
            mpp[t].push_back(it);
        }

        vector<vector<string>> ans;
        for (auto [str, vec] : mpp) {
            ans.push_back(vec);
        }

        return ans;
    }
};