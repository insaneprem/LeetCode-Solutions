class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] != 1)
                break;

            sum += nums[i];
        }

        set<int> st(begin(nums), end(nums));

        while (st.count(sum))
            sum++;

        return sum;
    }
};