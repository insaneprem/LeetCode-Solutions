class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int ans = 0, lastend = 0;

        ranges::sort(meetings);
        for (auto m : meetings) {
            int start = m[0], end = m[1];

            if (start > lastend) ans += -lastend + start - 1;

            lastend = max(lastend, end);
        }

        ans += days - lastend;

        return ans;
    }
};