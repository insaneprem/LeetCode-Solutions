class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int ans = 1e9, n = cards.size();
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(cards[i]) != mp.end()) {
                ans = min(ans, i - mp[cards[i]] + 1);
            }

            mp[cards[i]] = i;
        }

        return ans == 1e9 ? -1 : ans;
    }
};