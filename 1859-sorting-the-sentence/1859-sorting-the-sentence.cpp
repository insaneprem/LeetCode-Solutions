class Solution {
public:
    string sortSentence(string s) {
        stringstream ss(s);
        string token;
        
        map<int,string> mpp;
        while(ss>>token){
            mpp[token.back()-'0']=token.substr(0,token.size()-1);
        }

        for(auto i:mpp) cout<<i.first<<" "<<i.second<<"\n";

        string str="";
        for(auto i:mpp){
            str+=i.second;
            str+=" ";
        }

        str.pop_back();

        return str;
    }
};