class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map <int, vector<int>> mpp;
        for (int i = 0; i < groupSizes.size(); i++) {
            mpp[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> ans;
        for (auto i : mpp) {
            cout<<i.first;
            vector<int> temp = i.second;
            int sz=i.first;
            vector<int> topush;

            for(int i=0;i<temp.size();i++){
                topush.push_back(temp[i]);
                if(topush.size() == sz){
                    ans.push_back(topush);
                    topush.clear();
                }
            }
        }

        return ans;
    }
};