class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost);

        int cnt = 0, ans = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            if (cnt == 2) {
                cnt = 0;
                continue;
            }
            cnt++;
            ans += cost[i];
        }

        return ans;
    }
};