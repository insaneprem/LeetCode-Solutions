class Solution {
public:
    const int MOD = 1e9 + 7;
    int countPermutations(vector<int>& complexity) {
        bool flag = 1;
        int n = complexity.size();
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= complexity[0]) {
                flag = 0;
                break;
            }
        }

        if (!flag)
            return 0;
        long long ans = 1;
        for (int i = 1; i <= n - 1; i++)
            ans = (ans * i) % MOD;

        return ans;
    }
};