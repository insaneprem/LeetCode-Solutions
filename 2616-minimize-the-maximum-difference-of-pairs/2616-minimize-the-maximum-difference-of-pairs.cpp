class Solution {
public:
    bool check(vector<int>& nums, int val, int p) {
        int count = 0;
        for (int i = 1; i < nums.size();) {
            if (nums[i] - nums[i - 1] <= val) {
                count++;
                i += 2;
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums.front();

        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(nums, mid, p)) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};
