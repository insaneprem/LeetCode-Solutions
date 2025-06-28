class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(nums);
        sort(begin(nums), end(nums));
        multiset<int> mst(begin(nums) + n - k, end(nums));

        // for(auto i:mst) cout<<i<<" ";
        vector<int> ans;
        for (auto num : temp) {
            if (mst.count(num)) {
                ans.push_back(num);
                mst.erase(mst.find(num));
            }
        }

        return ans;
    }
};