class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26, -1), last(26, -1);

        for (int i = 0; i < s.size(); i++) {
            if (first[s[i] - 'a'] == -1)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }

        int prev = -1, forw = 0;

        vector<int> ans;
        for (int i = 0; i < s.size(); i++) {
            forw = max(forw, last[s[i] - 'a']);

            if (i == forw) {
                ans.push_back(i - prev);
                prev = i;
            }
        }

        return ans;
    }
};