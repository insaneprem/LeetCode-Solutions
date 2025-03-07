class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int sz = 2000001;
        vector<bool> isPrime(sz, true);
        if (sz > 0) isPrime[0] = false;
        if (sz > 1) isPrime[1] = false;
        
        for (int i = 2; i * i < sz; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < sz; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int prev = -1;
        int mini = INT_MAX;
        vector<int> ans = {-1, -1};
        
        for (int i = left; i <= right; i++) {
            if (i < sz && isPrime[i]) {
                if (prev != -1) {
                    int gap = i - prev;
                    if (gap < mini) {
                        mini = gap;
                        ans = {prev, i};
                    }
                }
                prev = i;
            }
        }
        
        return ans;
    }
};
