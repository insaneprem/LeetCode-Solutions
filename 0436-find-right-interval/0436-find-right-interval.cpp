class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> start, end;

        for (int i = 0; i < n; i++) {
            start.push_back({intervals[i][0], i});
            end.push_back({intervals[i][1], i});
        }

        ranges::sort(start);
        ranges::sort(end);

        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++) {
            int st = end[i].first;
            int idx = end[i].second;

            auto it = lower_bound(begin(start), start.end(), make_pair(st,-1e9));

            if (it == start.end()) {
                ans[idx] = -1;
            }
            else{
                ans[idx] = it->second;
            }
        }

        return ans;
    }
};