class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1, r = m * n;

        while (l <= r) {
            int mid = (l + r) / 2;
            int cnt = 0;
            for (int i = 1; i <= m; i++) {
                cnt += min(mid / i, n);
            }
            cout << mid << " " << cnt << "\n";

            (cnt < k) ? l = mid + 1 : r = mid - 1;
        }

        return l;
    }
};