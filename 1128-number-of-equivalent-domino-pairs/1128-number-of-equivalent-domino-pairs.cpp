class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mpp;

        for (auto vec : dominoes) {
            int a = vec[0], b = vec[1];
            if (a > b)
                swap(a, b);
            mpp[{a, b}]++;
        }

        int ans = 0;
        for (auto i : mpp)
            ans += (i.second * (i.second - 1)) / 2;

        return ans;
    }
};