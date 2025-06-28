class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<string, int> mpp;

        for (int i = 0; i <= n - 10; i++) {
            string str = s.substr(i, 10);
            mpp[str]++;
        }

        vector<string> ans;
        for (auto& it : mpp) {
            if (it.second > 1)
                ans.push_back(it.first);
        }

        return ans;
    }
};
