class Solution {
public:
    bool check(multiset<int>& mst, int val, int valueDiff) {
        auto it = mst.upper_bound(val);

        if (it != mst.end()) {
            int v = *it;
            if (abs(v - val) <= valueDiff) {
                return true;
            }
        }

        if (it != mst.begin()) {
            it--;
            int v = *it;
            if (abs(v - val) <= valueDiff) {
                return true;
            }
        }

        return false;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff,
                                       int valueDiff) {
        //    a - b <= val
        //    b - a <= val

        int n = nums.size();
        // indexDiff--;
        multiset<int> mst;
        for (int i = 0; i < n; i++) {
            int val = nums[i];

            if (check(mst, val, valueDiff)) {
                cout << i + 1 << val;
                return true;
            }
            if (i >= indexDiff) {

                int prev = nums[i - indexDiff];

                if (mst.find(prev) != mst.end())
                    mst.erase(mst.find(prev));
            }
            mst.insert(val);
        }

        return false;
    }
};