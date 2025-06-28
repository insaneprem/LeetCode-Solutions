class Solution {
public:
    const int MOD1 = 1e9 + 7;
    const int MOD2 = 1e9 + 9;
    const int p1 = 31;
    const int p2 = 37;
    string longestPrefix(string s) {
        int n = s.size();
        vector<long long> hash1(n), hash2(n);
        vector<long long> pow1(n), pow2(n);

        hash1[0] = (s[0] - 'a' + 1), hash2[0] = (s[0] - 'a' + 1);
        pow1[0] = 1, pow2[0] = 1;

        for (int i = 1; i < n; i++) {
            pow1[i] = (pow1[i - 1] * p1) % MOD1;
            pow2[i] = (pow2[i - 1] * p2) % MOD2;

            hash1[i] = (hash1[i - 1] * p1 + (s[i] - 'a' + 1)) % MOD1;
            hash2[i] = (hash2[i - 1] * p2 + (s[i] - 'a' + 1)) % MOD2;
        }

        int maxLen = 0;

        for (int len = 1; len < n; len++) {
            long long Prefixhash1 = hash1[len - 1];
            long long Prefixhash2 = hash2[len - 1];

            long long Suffixhash1 = (hash1[n - 1] -
                               (hash1[n - 1 - len] * pow1[len]) % MOD1 + MOD1) %
                              MOD1;
            long long Suffixhash2 = (hash2[n - 1] -
                               (hash2[n - 1 - len] * pow2[len]) % MOD2 + MOD2) %
                              MOD2;

            if (Prefixhash1 == Suffixhash1 && Prefixhash2 == Suffixhash2) {
                maxLen = len;
            }
        }

        return s.substr(0,maxLen);
    }
};