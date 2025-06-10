class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (auto i : s) {
            freq[i - 'a']++;
        }
        
        vector<int> even, odd;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2 == 0) {
                even.push_back(freq[i]);
            } else {
                odd.push_back(freq[i]);
            }
        }
        
        if (even.empty() || odd.empty()) {
            return 0;
        }
        
        int max_odd = *max_element(odd.begin(), odd.end());
        int min_even = *min_element(even.begin(), even.end());
        
        return max_odd - min_even;
    }
};