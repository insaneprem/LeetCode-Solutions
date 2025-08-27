class TrieNode {
    public:
    string word;
    TrieNode* children[26];

    TrieNode() {
        memset(children, 0, sizeof(children));
        word = "";
    }
};

class Trie {
    public:
    TrieNode* root;

    Trie() { root = new TrieNode(); };

    void insert(string& word) {
        TrieNode* node = root;

        for (auto ch : word) {
            int idx = ch - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->word = word;
    }
};
class Solution {
public:
    string ispresent(TrieNode* node, string word) {
        for (auto ch : word) {

            int idx = ch - 'a';
            if (!node->children[idx])
                return "";
            node = node->children[idx];
            if (node->word != "")
                return node->word;
        }

        return "";
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* tree = new Trie();

        for (auto& str : dictionary) {
            tree->insert(str);
        }

        stringstream os(sentence);
        string word;
        string ans = "";
        while (os >> word) {
            string str = ispresent(tree->root, word);
            cout<<str<<" ";
            if (str != "") {
                ans += str + " ";
            } else {
                ans += word + " ";
            }
        }

        ans.pop_back();

        return ans;
    }
};