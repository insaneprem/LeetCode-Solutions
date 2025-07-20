class Solution {
public:
    bool isprime(int n) {
        if (n <= 1)
            return 0;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return 0;

        return 1;
    }
    long long splitArray(vector<int>& nums) {
        long long sum_a = 0, sum_b = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (isprime(i))
                sum_a += nums[i];
            else
                sum_b += nums[i];
        }

        return abs(sum_a - sum_b);
    }
};