class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> freq;
        for(auto &i:nums1) freq[i[0]]+=i[1];
        for(auto &i:nums2) freq[i[0]]+=i[1];

        vector<vector<int>> ans;

        for(auto i:freq) ans.push_back(vector<int> ({i.first,i.second}));

        return ans;
    }
};