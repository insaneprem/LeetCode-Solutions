class Solution {
public:
    const int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1, currsum = 0, ans = 0;

        for (auto& i : arr) {
            currsum += i;
            if (currsum % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }

            ans = ans % mod;
        }

        return ans;
    }
};