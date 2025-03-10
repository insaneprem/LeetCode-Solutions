class Solution {
public:
    int binomSmall(int n, int r) {
        int table[5][5] = {{1, 0, 0, 0, 0},
                           {1, 1, 0, 0, 0},
                           {1, 2, 1, 0, 0},
                           {1, 3, 3, 1, 0},
                           {1, 4, 1, 4, 1}};
        return table[n][r];
    }

    int binomMod5(int n, int r) {
        if (r > n)
            return 0;
        int result = 1;
        while (n > 0 || r > 0) {
            int n0 = n % 5;
            int r0 = r % 5;
            if (r0 > n0)
                return 0;
            result = (result * binomSmall(n0, r0)) % 5;
            n /= 5;
            r /= 5;
        }
        return result;
    }

    int binomMod2(int n, int r) {
        if (r < 0 || r > n)
            return 0;
        return ((n & r) == r) ? 1 : 0;
    }

    int binomMod10(int n, int r) {
        int m2 = binomMod2(n, r);
        int m5 = binomMod5(n, r);
        int x = m5;
        if (x % 2 != m2)
            x += 5;
        return x % 10;
    }

    int triangularSum(vector<int>& nums) {
        int n = nums.size() - 1;
        int res = 0;

        for (int i = 0; i < n + 1; i++) {
            int comb = binomMod10(n, i);
            res = (res + comb * nums[i]) % 10;
        }
        return res;
    }
};
