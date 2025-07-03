class Solution {
public:
    string gen(string str) {
        string temp = "";
        for (auto i : str)
            temp += (i >= 'a' && i < 'z') ? (char(i + 1)) : 'a';
        return temp;
    }
    char kthCharacter(int k) {
        string str = "a";
        while (str.size() < k)
            str += gen(str);
        cout << str;
        return str[k - 1];
    }
};