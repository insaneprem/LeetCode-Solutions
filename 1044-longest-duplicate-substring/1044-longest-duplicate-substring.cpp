class Solution {
public:
    const int MOD1 = 1e9 + 7;
    const int MOD2 = 1e9 + 9;
    const int p1 = 31;
    const int p2 = 37;

    int get_hash(string str, int p, int MOD) {
        long long hash = 0;

        for (auto ch : str)
            hash = (hash * p + (ch - 'a' + 1)) % MOD;

        return (int)hash;
    }
    string solve(int len, string s) {
        set<pair<int, int>> seen;
        int n = s.size();
        long long pow1 = 1, pow2 = 1;

        for (int i = 0; i < len - 1; i++) {
            pow1 = (pow1 * p1) % MOD1;
            pow2 = (pow2 * p2) % MOD2;
        }

        long long hash1 = get_hash(s.substr(0, len), p1, MOD1);
        long long hash2 = get_hash(s.substr(0, len), p2, MOD2);

        seen.insert({hash1, hash2});
        for (int i = len; i < n; i++) {
            int to_delete1 = ((s[i - len] - 'a' + 1) * pow1) % MOD1;
            int to_add = (s[i] - 'a' + 1);

            hash1 = ((hash1 - to_delete1 + MOD1) * p1 + to_add) % MOD1;

            int to_delete2 = ((s[i - len] - 'a' + 1) * pow2) % MOD2;

            hash2 = ((hash2 - to_delete2 + MOD2) * p2 + to_add) % MOD2;

            if (seen.find({hash1, hash2}) != seen.end())
                return s.substr(i - len + 1, len);

            seen.insert({hash1, hash2});
        }

        return "";
    }
    string longestDupSubstring(string s) {
        int n = s.size();
        int l = 1, r = n;
        string ans = "";
        while (l <= r) {
            int mid = (l + r) / 2;
            string candidate = solve(mid, s);

            if (!candidate.empty()) {
                ans = candidate;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }
};