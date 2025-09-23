class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        stringstream s1(version1), s2(version2);
        string token;

        while (getline(s1, token, '.'))
            v1.push_back(stoi(token));
        while (getline(s2, token, '.'))
            v2.push_back(stoi(token));

        int n = v1.size();
        int m = v2.size();
        int i;
        for (i = 0; i < min(n, m); i++) {
            if (v1[i] < v2[i])
                return -1;
            else if (v1[i] > v2[i])
                return 1;
        }

        if (i < n) {

            for (i; i < n; i++)
                if (v1[i] > 0)
                    return 1;
        }
        if (i < m)
            for (i; i < m; i++)
                if (v2[i] > 0)
                    return -1;

        return 0;
    }
};