class Solution {
public:
    bool solve(int n,int base){
        string str="";
        while(n){
            str+=to_string(n%base);
            n/=base;
        }

        return str == (string(str.rbegin(),str.rend()));
    }
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2;i<=n-2;i++){
            if(!solve(n,i)) return 0;
        }

        return 1;
    }
};