class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastone = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                if (lastone != -1 && (i - lastone - 1) < k) return 0;
                lastone = i;
            }
        }
        return 1;
    }
};