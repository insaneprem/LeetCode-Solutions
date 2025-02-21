class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int index = 0;
        int ans = accumulate(
            customers.begin(), customers.end(), 0, [&](int sum, int customer) {
                return sum + (grumpy[index++] == 0 ? customer : 0);
        });
        
        int maxizerosum=0;
   
        for (int i = 0; i < index; i++) {
            int currsum=0;
            for(int j=i;j<min(i+minutes,index);j++){
                if(grumpy[j] == 1){
                    currsum+=customers[j];
                }
            }
            maxizerosum=max(maxizerosum,currsum);
        }
    

        return ans+maxizerosum;
    }
};