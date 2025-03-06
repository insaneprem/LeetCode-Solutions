class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int xr=0;
        for(auto i:grid){
            for(auto j:i){
                xr^=j;
            }
        }

        for(int i=1;i<=n*n;i++) xr^=i;

        int num=xr & ~(xr-1);
        int zero=0,one=0;

        for(auto i:grid){
            for(auto j:i){
                if(j & num) one^=j;
                else zero^=j;
            }
        }

        for(int i=1;i<=n*n;i++){
            if(i & num) one^=i;
            else zero^=i;
        }

        int cnt=0;
        
        for(auto i:grid){
            for(auto j:i){
                if(j == zero) cnt++;
            }
        }

        if(cnt == 2) return {zero,one};
        return {one,zero};

        
    }
};