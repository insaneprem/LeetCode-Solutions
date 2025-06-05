class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> freq;
        for (auto i : nums)
            freq[i]++;

        priority_queue<pair<int, int>> pq;
        for (auto it : freq)
            pq.push({it.second, it.first});

        vector<int> ans;
        while (k-- && !pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
