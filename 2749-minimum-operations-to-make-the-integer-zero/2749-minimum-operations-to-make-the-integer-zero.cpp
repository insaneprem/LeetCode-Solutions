class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (int step = 1; step <= 60; step++) {
            long long diff = 1LL * num1 - 1LL * step * num2;
            if (diff < 0) continue;

            int bitCount = __builtin_popcountll(diff);
            if (bitCount <= step && step <= diff) return step;
        }
        return -1;
    }
};
