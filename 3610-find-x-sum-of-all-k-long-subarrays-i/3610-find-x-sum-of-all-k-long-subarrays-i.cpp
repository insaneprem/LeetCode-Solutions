class Solution {
public:
    int getXSum(map<int,int> &mpp,int x){
            priority_queue<pair<int, int>> pq;
            for (auto& it : mpp) {
                pq.push({it.second, it.first});  
            }
            
            int sum = 0;
            int count = 0;
            while (!pq.empty() && count < x) {
                auto [frequency, value] = pq.top(); pq.pop();
                sum += value * frequency;
                count++;
            }
            return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        map<int, int> map;  
       
        for (int i = 0; i < nums.size(); ++i) {
            if(i>=k) map[nums[i - k]]--;
            if (i>=k && map[nums[i - k]] == 0) map.erase(nums[i - k]);
            map[nums[i]]++;
            if(i>=k-1) ans.push_back(getXSum(map,x));
        }

        return ans;
    }
};
