class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0, ans = 0, n = bank.size();

        for (int i = 0; i < n; i++) {
            int cnt = count(begin(bank[i]), end(bank[i]), '1');
            if (cnt == 0)
                continue;

            if (prev)
                ans += cnt * prev;
            
            prev = cnt;
        }

        return ans;
    }
};