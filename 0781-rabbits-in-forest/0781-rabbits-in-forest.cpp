class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> mpp;
        for (int i : answers) mpp[i]++;
        int res = 0;
        for (auto i : mpp) res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        return res;  
    }
};