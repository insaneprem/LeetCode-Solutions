class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l = 1, r = 1e9;
        while (l <= r) {
            long long mid = (l + r) / 2, n = 0;

            for (auto i : candies) n += (i) / mid;

            (n >= k) ? l = mid + 1 : r = mid - 1;
        }

        return r;
    }
};