class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n(stones.size());
        map<int, set<int>> mpp;
        mpp[1].insert({1});

        for (int i = 1; i < n; i++) {
            for (auto prev_jump : mpp[stones[i]]) {
                mpp[stones[i] + prev_jump - 1].insert(prev_jump - 1);
                mpp[stones[i] + prev_jump].insert(prev_jump);
                mpp[stones[i] + prev_jump + 1].insert(prev_jump + 1);
            }
        }

        return mpp[stones.back()].size();
    }
};