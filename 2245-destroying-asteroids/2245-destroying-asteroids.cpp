class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ranges::sort(asteroids);
        long long val=mass;
        for(auto i:asteroids){
            if(val>=i) val+=i;
            else return false;
        }

        return true;
    }
};