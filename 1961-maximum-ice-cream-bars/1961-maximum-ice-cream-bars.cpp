class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ranges::sort(costs);
        int ans=0;
        for(auto i:costs){
           if(coins-i<0) break;
           ans++;
           coins-=i;
        }
        
        return ans;
    }
};