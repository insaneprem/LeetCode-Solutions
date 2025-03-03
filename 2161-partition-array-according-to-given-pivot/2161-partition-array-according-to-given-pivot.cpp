class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less,equal,greater;

        for(auto &i:nums){
            if(i == pivot) equal.push_back(i);
            else if(i<pivot) less.push_back(i);
            else greater.push_back(i);
        }

        less.insert(less.end(),equal.begin(),equal.end());
        less.insert(less.end(),greater.begin(),greater.end());


        return less;
    }
};