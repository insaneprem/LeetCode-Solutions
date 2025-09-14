class Solution {
public:
    unordered_set<string> exactWords;
    unordered_map<string, string> caseMap;
    unordered_map<string, string> vowelMap;

    string toLower(string& s) {
        string res = s;
        for (auto& c : res)
            c = tolower(c);
        return res;
    }

    string maskVowels(string& s) {
        string res = s;
        for (char& c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                c = '*';
            }
        }
        return res;
    }

    string checkForMatch(string& query) {
        if (exactWords.count(query)) {
            return query;
        }

        string lowerQuery = toLower(query);
        if (caseMap.count(lowerQuery)) {
            return caseMap[lowerQuery];
        }

        string maskedQuery = maskVowels(lowerQuery);
        if (vowelMap.count(maskedQuery)) {
            return vowelMap[maskedQuery];
        }

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        exactWords.clear();
        caseMap.clear();
        vowelMap.clear();

        for (string word : wordlist) {
            exactWords.insert(word);

            string lowerWord = toLower(word);
            if (caseMap.find(lowerWord) == caseMap.end()) {
                caseMap[lowerWord] = word;
            }

            string maskedWord = maskVowels(lowerWord);
            if (vowelMap.find(maskedWord) == vowelMap.end()) {
                vowelMap[maskedWord] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            result.push_back(checkForMatch(query));
        }
        return result;
    }
};
