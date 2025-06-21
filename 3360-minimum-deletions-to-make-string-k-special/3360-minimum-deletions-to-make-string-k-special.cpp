class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> freq;
        for (auto& ch : word) freq[ch]++;

        int res = word.size();
        for (auto& [_, a] : freq) {
            int deleted = 0;
            for (auto& [_, b] : freq) {
                if (a > b) {
                    deleted += b;
                } else if (b > a + k) {
                    deleted += b - (a + k);
                }
            }
            res = min(res, deleted);
        }
        return res;
    }
};