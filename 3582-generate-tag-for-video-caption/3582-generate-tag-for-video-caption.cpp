class Solution {
public:
    bool ischar(char ch) {
        return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
    }
    string generateTag(string caption) {
        string ans = "#";

        stringstream ss(caption);
        string token = "";
        bool flag = 0;

        while (ss >> token) {
            string temp = "";
            for (auto i : token) {
                if (ischar(i))
                    temp += tolower(i);
            }
            if (!flag) {
                flag = 1;
            }
            else{
                temp[0]= toupper(temp[0]);
            }

            ans.append(temp);
        }

        return ans.substr(0,100);
    }
};