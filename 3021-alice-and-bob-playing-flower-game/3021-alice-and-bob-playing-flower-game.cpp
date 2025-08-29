class Solution {
public:
    long long flowerGame(int n, int m) {
        long long even_n = n/2;
        long long odd_n = n/2 + (n&1);

        long long even_m = m/2;
        long long odd_m = m/2 + (m&1);
      
        return (long long) (even_n * odd_m) + (even_m * odd_n);
    }
};