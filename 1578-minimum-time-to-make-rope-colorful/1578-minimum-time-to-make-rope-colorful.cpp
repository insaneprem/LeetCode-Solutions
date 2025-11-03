class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();

        int ans = 0;
        int maxi = neededTime[0];
        int currsum = neededTime[0];
        for (int i = 1; i < n; i++) {
            if (colors[i - 1] == colors[i]) {
                currsum += neededTime[i];
                maxi = max(maxi , neededTime[i]);
            } else {
                ans += currsum - maxi;
                currsum = neededTime[i];
                maxi = neededTime[i];
            }
        }
        
        ans += currsum - maxi;
        return ans;
    }
};