class Solution {
public:
    bool isValidchar(char ch) {
        return ((ch == '_') || (ch >= 'a' && ch <= 'z') ||
                (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
    }
    bool isValidcode(string& code) {
        if(code == "") return false;
        for (auto& i : code) {
            if (!isValidchar(i))
                return false;
        }
        return true;
    }
    bool isValidcat(string str) {
        return ((str == "electronics") || (str == "grocery") ||
                (str == "pharmacy") || (str == "restaurant"));
    }

    vector<string> validateCoupons(vector<string>& code,
                                   vector<string>& businessLine,
                                   vector<bool>& isActive) {
        vector<pair<string, string>> vec;
        int n = code.size();
        for (int i = 0; i < n; i++) {
            if (isValidcode(code[i]) && isValidcat(businessLine[i]) && isActive[i]) {
                vec.push_back({businessLine[i], code[i]});
            }
        }
        cout<<endl;

        auto getRank =
            [&](auto a) {
                if (a == "electronics")
                    return 1;
                else if (a == "grocery")
                    return 2;
                else if (a == "pharmacy")
                    return 3;

                return 4;
            };

        sort(begin(vec), end(vec), [&](auto a, auto b) {
            if (getRank(a.first) == getRank(b.first))
                return a.second < b.second;

            return getRank(a.first) < getRank(b.first);
        });

        vector<string> ans;

        for (int i = 0; i < vec.size(); i++){
            ans.push_back(vec[i].second);
        }

        return ans;
    }
};