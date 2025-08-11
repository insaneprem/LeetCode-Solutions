class Solution {
public:
    const int MOD = 1e9 + 7;
    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b) {
            if (b & 1)
                res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> arr;

        for (int i = 0; i < 32; i++) {
            if (n & (1 << i))
                arr.push_back(1LL << i);
        }

        for (int i = 1; i < arr.size(); i++)
            arr[i] = (1LL * arr[i - 1] * arr[i]) % MOD;

        vector<int> ans;

        for (auto q : queries) {
            int l = q[0], r = q[1];

            int res;
            if (l == 0)
                res = arr[r];
            else
                res = arr[r] * modPow(arr[l - 1], MOD - 2) % MOD;

            ans.push_back(res);
        }

        return ans;
    }
};