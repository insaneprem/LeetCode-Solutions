class Solution {
public:
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (root == NULL) return {0, 0};
        
        pair<int, int> leftSubtree = dfs(root->left);
        pair<int, int> rightSubtree = dfs(root->right);

        int nodesum = leftSubtree.first + rightSubtree.first + root->val;
        int nodecnt = leftSubtree.second + rightSubtree.second + 1;

        if (nodesum / nodecnt == root->val) {
            ans++;
        }

        return {nodesum, nodecnt};
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};