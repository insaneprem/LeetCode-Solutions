class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0, leftmaxi = 0, maxdiff = 0;

        for (auto i : nums) {
            ans = max(ans, maxdiff * i);
            leftmaxi = max(leftmaxi, i * 1LL);
            maxdiff = max(maxdiff, leftmaxi - i);
        }

        return ans;
    }
};