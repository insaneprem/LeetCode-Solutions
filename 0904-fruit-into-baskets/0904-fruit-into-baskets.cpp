class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0, r = 0;
        map<int, int> mp;
        int maxLen = 1;
        while (r < n) {
            while (r < n) {
                mp[fruits[r]]++;

                while (mp.size() > 2) {
                    if (--mp[fruits[l]] == 0)
                        mp.erase(fruits[l]);
                    l++;
                }

                maxLen = max(maxLen, r - l + 1);

                r++;
            }
        }

        return maxLen;
    }
};