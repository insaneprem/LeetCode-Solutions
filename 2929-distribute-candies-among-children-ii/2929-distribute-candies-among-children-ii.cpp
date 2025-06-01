class Solution {
public:
    long long solve(long long n, long long r) {
        long long ans = 1;
        for (int i = 1; i <= min(r, n - r); i++) ans = (ans * (n - i + 1)) / i;
        return ans;
    }

    long long distributeCandies(int n, int limit) {
       long long way = 0, sign = 1;

        for (int i = 1; i <= 3; i++) {
            if (n >= i * (limit + 1)) way += sign * solve(n - i * (limit + 1) + 2, 2) * 3;
            sign *= -1; 
        }

        return max(solve(n + 2, 2) - way, 0LL);
    }
};
