class Solution {
public:
    int minMaxDifference(int num) {
        string snum = to_string(num);
        string maxi = snum, mini = snum;

        for (int i = 0; i < snum.size(); i++) {
            if (snum[i] < '9') {
                replace(begin(maxi), end(maxi), snum[i], '9');
                break;
            }
        }

        for (int i = 0; i < snum.size(); i++) {
            if (snum[i] > '0') {
                replace(begin(mini), end(mini), snum[i], '0');
                break;
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};