class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        set<int> st;
        vector<int> ans;

        for (auto& i : nums) {
            if (!st.insert(i).second)
                ans.push_back(i);
        }
        return ans;
    }
};