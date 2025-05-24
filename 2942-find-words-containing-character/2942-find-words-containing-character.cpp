class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;

        for(int _=0;_<words.size();_++){
            if(words[_].find(x) == string::npos) continue;
            ans.push_back(_);
        }

        return ans;
    }
};