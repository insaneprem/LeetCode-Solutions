class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> freq;

        for (auto i : arr)
            freq[i]++;

        int ans = -1;

        for (auto [num, cnt] : freq) {
            if (num == cnt)
                ans = num;
        }
        return ans;
    }
};