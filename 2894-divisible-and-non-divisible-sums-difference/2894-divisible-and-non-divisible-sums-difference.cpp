class Solution {
public:
    int differenceOfSums(int n, int m) {

        int total = (n * (n + 1)) / 2, terms = n / m;

        return total - (terms * (2 * m + (terms - 1) * m));
    }
};