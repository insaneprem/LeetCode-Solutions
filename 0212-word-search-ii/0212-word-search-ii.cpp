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
    Trie() { root = new TrieNode(); }

    void insert(string word) {
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
    int n, m;
    bool isValid(int r, int c) { return (r >= 0 && c >= 0 && r < n && c < m); }
    vector<string> ans;
    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* node) {
        if (!isValid(r, c) || board[r][c] == '$')
            return;

        char ch = board[r][c];
        int idx = ch - 'a';

        if (!node->children[idx])
            return;

        TrieNode* nextNode = node->children[idx];

        if (nextNode->word != "") {
            ans.push_back(nextNode->word);
            nextNode->word = "";
        }

        board[r][c] = '$';
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (abs(i) == abs(j))
                    continue;

                int nr = r + i;
                int nc = c + j;

                dfs(nr, nc, board, nextNode);
            }
        }

        board[r][c] = ch;
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        this->n = board.size();
        this->m = board[0].size();
        ans.clear();

        Trie* tree = new Trie();

        for (auto str : words) {
            tree->insert(str);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, board, tree->root);
            }
        }

        return ans;
    }
};