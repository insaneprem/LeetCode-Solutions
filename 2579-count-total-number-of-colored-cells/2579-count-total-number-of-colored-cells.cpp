class Solution {
public:
    long long coloredCells(int n) {

        long long ans = 0;
        for (int i = 2 * n - 1; i >= 0; i -= 2) ans += i;
        ans *= 2, ans -= 2 * n - 1;

        return ans;
    }
};