class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans=0;
        string match="";
        while(match.size()<b.size()){
            ans++;
            match+=a;
        }

        if(match.find(b) != string::npos) return ans;
        match+=a;
        if(match.find(b) != string::npos) return ans+1;
        return -1;
    }
};