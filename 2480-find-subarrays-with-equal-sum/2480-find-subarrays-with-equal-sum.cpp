class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        set<int> st;
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            int val=nums[i]+nums[i+1];
            if(st.find(val) != st.end()) return 1;
            st.insert(val);
        }

        return 0;
    }
};