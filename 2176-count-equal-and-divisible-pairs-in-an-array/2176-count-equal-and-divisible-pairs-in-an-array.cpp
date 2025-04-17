class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        vector<int> divs;
        unordered_map<int, int> divIndex;
        for (int d = 1; d * d <= k; ++d) {
            if (k % d == 0) {
                divs.push_back(d);
                if (d * d != k) divs.push_back(k / d);
            }
        }
        sort(divs.begin(), divs.end());
        for (int i = 0; i < divs.size(); i++) divIndex[divs[i]] = i;

        map<int, vector<long long>> freq;
        long long ans = 0;
        for (int j = 0; j < nums.size(); j++) {
            int g = gcd(j, k), need = k / g;
            auto& f = freq[nums[j]];
            if (f.empty()) f.resize(divs.size());

            ans += f[divIndex[need]];
            for (int i = 0; i < divs.size(); i++) if (j % divs[i] == 0) f[i]++;
        }

        return ans;
    }
};
