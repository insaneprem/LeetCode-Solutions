class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        vector<int> prefix = nums;
        partial_sum(begin(prefix), end(prefix), begin(prefix));

        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int leftsum = 0;
            if (i > 0)
                leftsum = prefix[i - 1];
            int rightsum = prefix[n - 1] - prefix[i];

            if (nums[i] == 0) {
                if (abs(leftsum - rightsum) == 1)
                    ans++;
                else if (abs(leftsum - rightsum) == 0)
                    ans += 2;
            }
        }

        return ans;

        return ans;
    }
};