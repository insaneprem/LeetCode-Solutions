class Solution {
public:
    bool isprime(int n) {
        if (n <= 1)
            return 0;
        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;

        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int, int> freq;
        for (auto i : nums)
            freq[i]++;
        
        for(auto i:freq) if(isprime(i.second)) return true;

        return false;
    }
};