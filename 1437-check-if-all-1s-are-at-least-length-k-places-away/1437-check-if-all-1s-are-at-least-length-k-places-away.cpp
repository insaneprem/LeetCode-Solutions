class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        int lastone = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                if (lastone != -1 && i - lastone <= k)
                    return false;
                lastone = i;
            }

        }

        return true;
    }
};