class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> freq;

        for (auto i : basket1) freq[i]++;
        for (auto i : basket2) freq[i]--;

        vector<int> excess;

        for (auto &[val, count] : freq) {
            if (count % 2 != 0) return -1; 
            for (int i = 0; i < abs(count) / 2; i++)
                excess.push_back(val);
        }

        sort(excess.begin(), excess.end());

        int n = excess.size();
        int min_elem = min(*min_element(basket1.begin(), basket1.end()),
                           *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < n / 2; i++) {
            cost += min(excess[i], 2 * min_elem);
        }

        return cost;
    }
};
