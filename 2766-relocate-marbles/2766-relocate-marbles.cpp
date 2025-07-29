class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom,
                                vector<int>& moveTo) {
        set<int> st(begin(nums), end(nums));
        int n = moveFrom.size();
        for (int i = 0; i < n; i++) {
            st.erase(moveFrom[i]);
            st.insert(moveTo[i]);
        }

        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};