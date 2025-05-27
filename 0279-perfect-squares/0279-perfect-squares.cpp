class Solution {
public:
    int numSquares(int n) {
        int val = n;
        int sqrtval = sqrt(val);

        if (sqrtval * sqrtval == val)
            return 1;

        while (val % 4 == 0)
            val /= 4;
        if (val % 8 == 7)
            return 4;

        for (int i = 1; i * i <= n; i++) {
            int ps = i * i;
            int remval = n - ps;
            int sqrtrem = sqrt(remval);
            if (sqrtrem * sqrtrem == remval)
                return 2;
        }

        return 3;
    }
};