class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (auto row : grid)
           for(auto num:row)
            arr.push_back(num);

        ranges::sort(arr);

        int val = arr[arr.size() / 2], ans = 0;

        for (auto i : arr) {
            if (abs(i - val) % x != 0)
                return -1;

            ans += abs(i - val)/x;
        }

        return ans;
    }
};