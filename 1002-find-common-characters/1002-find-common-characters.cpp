class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        for(int i=0;i<26;i++){
            int time=1e9;
            for(auto word:words){
                int chcnt=count(word.begin(),word.end(),char(i+'a'));
                time=min(time,chcnt);
            }
            string temp="";
            temp+=char(i+'a');
            for(int k=0;k<time;k++) ans.push_back(temp);
        }

        return ans;
    }
};