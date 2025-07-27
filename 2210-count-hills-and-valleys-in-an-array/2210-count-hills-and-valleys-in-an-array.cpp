class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> arr(1, nums[0]);

        for (auto i : nums) {
            if (arr.back() != i)
                arr.push_back(i);
        }

        int n = arr.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
            ans += ((arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) ||
                    (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]));

        return ans;
    }
};