class Solution {
public:
    typedef pair<int, int> P;
    const int mod = 1e9 + 7;

    int countprime(int n) {
        int cnt = 0;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                while (n % i == 0)  n = n / i;
            }
        }

        return (n>1) ? cnt+1 : cnt;
    }

    long long modexp(long long base, long long exp, long long mod) {
        long long res = 1;

        while (exp > 0) {
            if (exp % 2 == 1)  res = (res * base) % mod;
            base = (base * base) % mod; 
            exp /= 2;
        }

        return res;
    }

    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prime(n);
        for (int i = 0; i < n; i++) prime[i] = countprime(nums[i]);

        priority_queue<P> pq;
        for (int i = 0; i < n; i++) pq.push({nums[i], i});

        long long ans = 1;
        while (k > 0) {
            auto [maxi, idx] = pq.top();
            pq.pop();

            long long maxcount = prime[idx], leftcnt = 1, rightcnt = 0, prev = idx - 1;

            while (prev >= 0 && prime[prev] < maxcount) leftcnt++, prev--;
            while (idx < n && prime[idx] <= maxcount) rightcnt++, idx++;
            
            long long ele=(rightcnt * leftcnt);
            long long take = min(k*1LL, ele );
            k -= take;

            ans = (ans * modexp(maxi, take, mod)) % mod;
        }

        return ans;
    }
};
