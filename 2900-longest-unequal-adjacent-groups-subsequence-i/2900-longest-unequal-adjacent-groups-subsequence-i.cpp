class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int i=0;
        vector<string>ans;
        ans.push_back(words[i]);
        for(int i=1;i<words.size();i++){
            if(groups[i]!=groups[i-1])
            ans.push_back(words[i]);
        }
        return ans;
    }
};