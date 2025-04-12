class Solution {
    void solve(
        int n, 
        int k, 
        int idx, 
        map<int, int>&mp,
        set<map<int, int>>&st,
        string&curr
    ) {
        if (idx == (n + 1) / 2) {
            for(int i = n / 2 - 1; i >= 0; i--) {
                curr.push_back(curr[i]);
                mp[curr[i]-'0']++;
            }
            long long num = stoll(curr);
            if (num%k == 0) {
                st.insert(mp);
            }
            for(int i = n / 2 - 1; i >= 0; i--) {
                mp[curr[i]-'0']--;
                curr.pop_back();
            }
            return;
        }
        for (int i=0; i<=9; i++) {
            curr.push_back(i+'0');
            mp[i]++;
            solve(n, k, idx+1, mp, st, curr);
            mp[i]--;
            curr.pop_back();
        }
    }
    long long fact(
        int x,
        unordered_map<int, long long>& dp
    ) {
        if (x == 0) return 1;
        if (dp.count(x)) return dp[x];
        return dp[x] = x * fact(x - 1, dp);
    }
    long long count_perm(
        map<int, int>&mp,
        unordered_map<int, long long>& dp
    ) {
        int n = 0;
        for (auto& elem: mp) {
            n += elem.second;
        }
        long long ans = fact(n, dp);
        for (auto&[_, x]: mp) {
            ans /= fact(x, dp);
        }
        return ans;
    }
public:
    long long countGoodIntegers(int n, int k) {
        map<int, int> mp;
        set<map<int, int>> st;
        string curr;
        for (int i=1; i<=9; i++) {
            curr.push_back(i+'0');
            mp[i]++;
            solve(n, k, 1, mp, st, curr);
            mp[i]--;
            curr.pop_back();
        }
        long long ans = 0;
        unordered_map<int, long long> dp;
        for (auto m: st) {
            ans += count_perm(m, dp);
            if (m[0] != 0) {
                m[0]--;
                ans -= count_perm(m, dp);
            }
        }
        return ans;
    }
};