class Solution {
public:
    int sumBase(int n, int k) {
        int result = 0;

        while (n) result += n % k, n /= k;

        return result;
    }
};