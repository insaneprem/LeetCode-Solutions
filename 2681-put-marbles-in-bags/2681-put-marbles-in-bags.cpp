class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if (k == 1) return 0;

        vector<int> arr;
        for (int i = 1; i < n; i++) arr.push_back(weights[i] + weights[i - 1]);

        ranges::sort(arr);

        return accumulate(arr.end() - (k - 1), arr.end(), 0LL) - accumulate(arr.begin(), arr.begin() + (k - 1), 0LL);
    }
};
