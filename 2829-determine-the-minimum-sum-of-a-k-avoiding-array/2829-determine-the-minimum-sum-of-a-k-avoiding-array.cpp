class Solution {
public:
    int minimumSum(int n, int k) {
        map<int, int> mp;
        int ans = 0;

        for (int i = 1; n; i++) {
            if (mp.count(i))
                continue;
            ans += i;
            n--;
            mp[k-i] = 1;
        }

        return ans;
    }
};