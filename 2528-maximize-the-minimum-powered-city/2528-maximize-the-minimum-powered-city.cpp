class Solution {
public:
    bool check(vector<int> stations, int r, int k, long long mid) {
        vector<long long> vec(begin(stations), end(stations));

        partial_sum(begin(vec), end(vec), begin(vec));
        int n = vec.size();
        vector<long long> diffarr(n + 1, 0);
        long long curr = 0;
        for (int i = 0; i < n; i++) {
            curr += diffarr[i];
            int rightidx = min(n - 1, i + r);
            int leftidx = i - r - 1;
            long long windowsum =
                vec[rightidx] - (leftidx < 0 ? 0 : vec[leftidx]);
            // cout<<windowsum<<" ";
            // cout << windowsum + curr << " " << curr << "\n";

            if (windowsum + curr < mid) {
                long long need = mid - (windowsum + curr);
                if (need > k)
                    return false;
                diffarr[min(n, i + r + r + 1)] -= need;
                curr += need;
                k -= need;
            }
        }

        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long low = 0, high = 1e16;

        while (low <= high) {
            long long mid = (low + high) >> 1;

            if (check(stations, r, k, mid))
                low = mid + 1;
            else
                high = mid - 1;
        }

        return high;
    }
};