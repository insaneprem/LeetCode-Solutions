class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char,int> mpp;
        for(auto i:text) mpp[i]++;

        int ans=1e9;
        ans=min({mpp['b'],mpp['a'],mpp['l']/2,mpp['o']/2,mpp['n']});
        return ans;
    }
};