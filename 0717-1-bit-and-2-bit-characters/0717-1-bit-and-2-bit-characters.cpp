class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) { 
        int l = 0 , n = bits.size();

        while(l<n){
            if(l == n -1 ) return true;

            if(bits[l] == 1) l = l + 2;
            else l = l + 1;
        }

        return false;
    }
};