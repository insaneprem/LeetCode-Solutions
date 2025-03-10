class Solution {
public:
    int scoreOfString(string s) {
        int ans=0,n=s.size();

        for(int i=0;i<n;i++){
            if(i+1<n) ans+=abs(s[i]-s[i+1]);
        }
        return ans;
    }
};