class Solution {
public:
    bool checkDivisibility(int n) {
        string str = to_string(n);
        int sum = 0, product = 1;
        for (auto ch : str) {
            int dig = ch - '0';
            sum += dig;
            product *= dig;
        }

        return n % (sum + product) == 0;
    }
};