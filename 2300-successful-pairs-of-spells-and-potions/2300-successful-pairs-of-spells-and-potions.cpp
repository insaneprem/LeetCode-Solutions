class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size(),m=potions.size();
        sort(begin(potions),end(potions));

        vector<int> ans;
        
        for(auto num:spells){
            long long val = (success + num - 1)/num;

            auto it = lower_bound(begin(potions),end(potions),val);

            ans.push_back(distance(it,potions.end()));
        }

        return ans;
    }
};