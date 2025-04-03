class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, maxdiff = 0, leftmax = 0;

        for (auto& i : nums) {
            ans = max(ans, maxdiff * i);
            leftmax = max(leftmax, i * 1LL);
            maxdiff = max(maxdiff, leftmax - i);
        }

        return ans;
    }
};