class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 0, r = 1e9, n = nums.size();

        while (l <= r) {
            int mid = (l + r) / 2, house = 0;

            for (int i = 0; i < n; i++) if (nums[i] <= mid) house++, i++;

            (house < k) ? l = mid + 1 : r = mid - 1;
        }

        return l;
    }
};