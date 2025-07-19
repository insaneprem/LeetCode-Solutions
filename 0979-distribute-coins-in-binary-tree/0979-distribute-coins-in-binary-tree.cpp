class Solution {
public:
    int moves = 0;
    int dfs(TreeNode* node) {
        if (!node) return 0; 
        
        int left_balance = dfs(node->left);
        int right_balance = dfs(node->right);

        moves += abs(left_balance) + abs(right_balance);

        return (node->val - 1) + left_balance + right_balance;
    }

    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};