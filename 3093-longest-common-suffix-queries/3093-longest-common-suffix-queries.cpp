class TrieNode {
public:
    int BestIdx;
    int children[26];

    TrieNode() {
        memset(children, 0, sizeof(children));
        BestIdx = -1;
    }
};

class Trie {
public:
    vector<TrieNode> pool;
    int root;

    Trie() {
        pool.emplace_back(); 
        pool.emplace_back();
        root = 1;
    };


    bool isBetter(int idx1, int idx2, vector<string>& wordsContainer) {
        if (idx2 == -1) return true;
        if (idx1 == -1) return false;

        int sz1 = (int)wordsContainer[idx1].size();
        int sz2 = (int)wordsContainer[idx2].size();

        if (sz1 == sz2) return idx1 < idx2;
        return sz1 < sz2;
    }

    void assignIdx(int newIdx, int& currentBestIdx, vector<string>& wordsContainer) {
        if (isBetter(newIdx, currentBestIdx, wordsContainer)) {
            currentBestIdx = newIdx;
        }
    }

    void insert(string& word, int widx, vector<string>& wordsContainer) {
        int currentNodeIdx = root;
        assignIdx(widx, pool[currentNodeIdx].BestIdx, wordsContainer);

        for (auto ch : word) {
            int charIdx = ch - 'a';
            if (pool[currentNodeIdx].children[charIdx] == 0) {
                pool[currentNodeIdx].children[charIdx] = pool.size();
                pool.emplace_back();
            }
            currentNodeIdx = pool[currentNodeIdx].children[charIdx];
            assignIdx(widx, pool[currentNodeIdx].BestIdx, wordsContainer);
        }
    }

    int search(string& word) {
        int currentNodeIdx = root;
        for (auto ch : word) {
            int charIdx = ch - 'a';
            if (pool[currentNodeIdx].children[charIdx] == 0) {
                return pool[currentNodeIdx].BestIdx;
            }
            currentNodeIdx = pool[currentNodeIdx].children[charIdx];
        }
        return pool[currentNodeIdx].BestIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        Trie tree;
        int n = wordsContainer.size();

        for (int i = 0; i < n; i++) {
            string str = wordsContainer[i];
            reverse(begin(str), end(str));
            tree.insert(str, i, wordsContainer);
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size()); 

        for (auto& w : wordsQuery) {
            reverse(begin(w), end(w));
            ans.push_back(tree.search(w));
        }

        return ans;
    }
};