class Solution {
public:
    int totalMoney(int n) {
        int term = n / 7;
        int rem = n % 7;
        int ans = (term * 28) + (term * ((term - 1) * 7)) / 2;
        ans += term * rem + rem * (rem + 1) / 2;

        return ans;
    }
};