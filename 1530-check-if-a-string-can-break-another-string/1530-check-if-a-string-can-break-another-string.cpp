class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        ranges::sort(s1);
        ranges::sort(s2);

        bool flag=1;

        for(int i=0;i<s1.size();i++) flag&=(s1[i]>=s2[i]);
        if(flag) return 1;
        flag=1;
        for(int i=0;i<s1.size();i++) flag&=(s1[i]<=s2[i]);

        return flag;
        // syz
        // cdi
    }
};