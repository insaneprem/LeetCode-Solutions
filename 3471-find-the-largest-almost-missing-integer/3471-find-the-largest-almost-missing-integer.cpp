class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;  

    
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> st;
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }
            for (auto i : st) {
                mpp[i]++;
            }
        }
        
        int ans = -1;
        
        for (auto &i : mpp) {
            if (i.second == 1) {
                ans = max(ans, i.first);
            }
        }
        
        return ans;
    }
};
