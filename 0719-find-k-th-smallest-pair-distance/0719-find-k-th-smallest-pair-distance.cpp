class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n = nums.size();

        int l = 0, r = nums[n - 1] - nums[0];

        while (l <= r) {
            int mid = (l + r) / 2, cnt = 0;

            for (int i = 0; i < n - 1; i++) {
                cnt += upper_bound(begin(nums), end(nums), nums[i] + mid) -
                       nums.begin() - 1 - i;
            }

            (cnt < k) ? l = mid + 1 : r = mid - 1;
        }

        return l;
    }
};