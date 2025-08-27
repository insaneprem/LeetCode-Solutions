class TrieNode {
public:
    TrieNode *left, *right;
    TrieNode() {
        left = nullptr;
        right = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* node = root;

        for (int i = 31; i >= 0; i--) {
            bool isSet = ((num) & (1 << i));
            if (isSet) {
                if (!node->right)
                    node -> right = new TrieNode();
                node = node->right;
            } else {
                if (!node->left)
                    node -> left = new TrieNode();
                node = node->left;
            }
        }
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* tree = new Trie();

        for (auto num : nums) {
            tree->insert(num);
        }
        
        int ans = 0;
        for (auto num : nums) {
            TrieNode* node = tree->root;

            int y = 0;
            for (int i = 31; i >= 0; i--) {
                bool isSet = (num & (1 << i));

                if (isSet) {
                    if (node->left)
                        node = node->left;
                    else {
                        y |= (1 << i);
                        node = node->right;
                    }
                } else {
                    if (node->right){
                        y |= (1 << i);
                        node = node->right;
                    }
                    else {
                        node = node->left;
                    }
                }
            }

            ans = max(ans, num ^ y);
        }

        return ans;
    }
};