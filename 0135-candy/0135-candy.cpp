class Solution {
public:
    int candy(vector<int>& ratings) {
        int down=0;
        int n=ratings.size();
        int  sum=1;
        
        int i=1;

        while(i<n){
            if(ratings[i] == ratings[i-1]){
                i++;
                sum++;
                continue;
            }

            int peak=1;
            while(i<n &&ratings[i]>ratings[i-1]){
                peak+=1;
                sum+=peak;
                i++;
            }
            int down=1;
            while(i<n &&ratings[i]<ratings[i-1]){
                sum+=down;
                down+=1;
                i++;
            }

            if(down>peak) sum+=down-peak;

        }
        return sum;
    }
};