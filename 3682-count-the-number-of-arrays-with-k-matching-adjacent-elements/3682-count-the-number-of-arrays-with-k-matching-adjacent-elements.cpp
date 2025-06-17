const long long mod = 1e9 + 7;

class Combitorics {
    vector<long long> fact;
    vector<long long> modinv;
    int N;

public:
    Combitorics(int n) {
        N = n;
        fact = vector<long long>(N + 1, 1);
        modinv = vector<long long>(N + 1, 1);
        precompute();
    }

    long long power(long long base, long long x) {
        if (x < 0) return 0;

        long long ans = 1;
        while (x) {
            if (x % 2 == 0) {
                base = (base * base) % mod;
                x /= 2;
            } else {
                ans = (ans * base) % mod;
                x--;
            }
        }
        return ans;
    }

    void precompute() {
        for (long long i = 1; i <= N; i++) {
            fact[i] = (fact[i - 1] * i) % mod;
            modinv[i] = power(fact[i], mod - 2);
        }
    }

    long long ncr(long long n, long long r) {
        if (n < 0 || r < 0 || r > n) return 0;

        long long numo = fact[n];
        long long ans = ((numo * modinv[r]) % mod * modinv[n - r]) % mod;
        return ans;
    }
};

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        Combitorics Pnc(n - 1);

        long long val = Pnc.power(m - 1, n - 1 - k) % mod;
        long long val2 = (Pnc.ncr(n - 1, k) * m) % mod;

        return (val * val2) % mod;
    }
};
