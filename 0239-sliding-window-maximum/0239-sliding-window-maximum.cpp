class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mst;
        int n = nums.size();

        vector<int> res;
        for (int i = 0; i < n; i++) {
            mst.insert(nums[i]);

            if (i >= k) {
                mst.erase(mst.find(nums[i - k]));
            }
            if (i >= k - 1)
                res.push_back(*mst.rbegin());
        }

        return res;
    }
};