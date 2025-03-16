class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2) return {};

        long long currsum = 0, num = 2;
        vector<long long> ans;
        
        while ((num + currsum) <= finalSum) {
            ans.push_back(num);
            currsum += num;
            num += 2;
        }

        ans[ans.size() - 1] += finalSum - currsum;
        return ans;
    }
};