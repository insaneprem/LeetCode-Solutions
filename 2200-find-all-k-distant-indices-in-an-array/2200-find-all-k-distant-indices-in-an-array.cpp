class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                for (int j = max(0, i - k); j < min(n, i + k + 1); j++)
                    st.insert(j);
            }
        }

        vector<int> ans;
        for (auto i : st)
            ans.push_back(i);

        return ans;
    }
};