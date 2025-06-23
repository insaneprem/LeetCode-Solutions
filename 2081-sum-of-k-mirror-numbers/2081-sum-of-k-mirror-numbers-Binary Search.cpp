class Solution {
public:
    long long kMirror(int k, int n) {
        auto isPalindrome = [&](long long x) -> bool {
            string temp = "";
            while (x) {
                temp += to_string(x % k);
                x /= k;
            }
            string rtemp = temp;
            reverse(begin(rtemp), end(rtemp));
            return temp == rtemp;
        };

        int left = 1, count = 0;
        long long ans = 0;
        while (count < n) {
            int right = left * 10;
            // op = 0 indicates enumerating odd-length palindromes
            // op = 1 indicates enumerating even-length palindromes
            for (int op = 0; op < 2; op++) {
                // enumerate i'
                for (int i = left; i < right && count < n; i++) {
                    long long combined = i;
                    int x = (op == 0 ? i / 10 : i);
                    
                    while (x) {
                        combined = combined * 10 + x % 10;
                        x /= 10;
                    }

                    if (isPalindrome(combined)) {
                        count++;
                        ans += combined;
                    }
                }
            }

            left = right;
        }
        return ans;
    }
};