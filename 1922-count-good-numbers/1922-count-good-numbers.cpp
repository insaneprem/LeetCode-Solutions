class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long mod_mul(long long a, long long b, long long m) {
        return (a % m * b % m) % m;
    }
    long long mod_exp(long long a, long long b, long long m) {
        if (b == 0)
            return 1;
        long long res = mod_exp(a, b / 2, m);
        res = mod_mul(res, res, m);

        if (b % 2 == 1)
            res = mod_mul(res, a, m);

        return res;
    }
    int countGoodNumbers(long long n) {
        long long fivechoice = (n + 1) / 2;
        long long fourchoice = n / 2;

        long long val1 = mod_exp(5, fivechoice, MOD);
        long long val2 = mod_exp(4, fourchoice, MOD);

        long long ans = mod_mul(val1, val2, MOD);

        return ans;
    }
};