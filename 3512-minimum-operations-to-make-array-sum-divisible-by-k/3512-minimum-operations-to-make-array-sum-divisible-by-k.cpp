class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = accumulate(begin(nums), end(nums), 0);
        return ans % k;
    }
};