class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 0, r = 1e18;
        ranges::sort(ranks);

        while (l <= r) {
            long long mid = (l + r) / 2, done = 0;
            
            for (auto i : ranks) {
                done += (int)sqrt(mid / i);
                if (done >= cars) break;
            }

            (done >= cars) ? r = mid - 1 : l = mid + 1;
        }
        return l;
    }
};
