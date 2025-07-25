class Solution {
public:
    vector<vector<int>> substringXorQueries(string s,
                                            vector<vector<int>>& queries) {
        int n = s.size();

        map<string, int> mpp;
        for (int len = 1; len < 31; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                string str = s.substr(i, len);
                if (mpp.find(str) == mpp.end()) {
                    mpp[str] = i;
                }
            }
        }

        vector<vector<int>> ans;
        for (auto q : queries) {
            int val = q[0] ^ q[1];

            string str = "";
            for (int i = 31; i >= 0; i--) {
                if (val & (1 << i))
                    str += '1';
                else
                    str += '0';
            }

            int idx = 0;

            while (idx < str.size() && str[idx] != '1')
                idx++;

            if (idx == str.size())
                str = '0';
            else
                str = str.substr(idx);

            if (mpp.find(str) != mpp.end())
                ans.push_back({mpp[str], mpp[str] + (int)str.size() - 1});
            else
                ans.push_back({-1, -1});
        }

        return ans;
    }
};