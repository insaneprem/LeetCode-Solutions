/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;

        int leftans = dfs(root->left);
        int rightans = dfs(root->right);

        int ans = 0;
        int rootVal = root->val;
        if (rootVal % 2 == 0) {
            if (root->left && root->left->left)
                ans += root->left->left->val;
            if (root->left && root->left->right)
                ans += root->left->right->val;
            if (root->right && root->right->left)
                ans += root->right->left->val;
            if (root->right && root->right->right)
                ans += root->right->right->val;
        }


        return leftans + rightans + ans;
    }
    int sumEvenGrandparent(TreeNode* root) { return dfs(root); }
};