class Solution {
public:
    vector<int> arr1, arr2;
    map<string, int> dp;
    int solve(int prev, int idx) {
        if (idx == arr1.size())
            return 0;

        string key = to_string(prev) + "_" + to_string(idx);
        if (dp.find(key) != dp.end())
            return dp[key];
        int res = INT_MAX >> 1;
        if (prev < arr1[idx])
            res = min(res, solve(arr1[idx], idx + 1));

        auto it = upper_bound(begin(arr2), end(arr2), prev);

        if (it != arr2.end()) {
            res = min(res, 1 + solve(*it, idx + 1));
        }

        return dp[key] = res;
    }
    int makeArrayIncreasing(vector<int>& a1, vector<int>& a2) {
        arr1 = a1;
        arr2 = a2;
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        int ans = solve(-1, 0);
        return (ans == INT_MAX >> 1) ? -1 : ans;
    }
};