class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cval(26);
        iota(begin(cval), end(cval), 1);

        for (int i = 0; i < chars.size(); i++) {
            char ch = chars[i];
            cval[ch - 'a'] = vals[i];
        }

        int currsum = 0, maxi = 0;

        for (auto i : s) {
            currsum += cval[i - 'a'];
            maxi = max(maxi, currsum);

            if (currsum < 0)
                currsum = 0;
        }

        return maxi;
    }
};