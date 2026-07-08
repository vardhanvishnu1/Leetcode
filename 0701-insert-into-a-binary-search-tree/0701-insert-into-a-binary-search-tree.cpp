class Solution {
public:
    void solve(TreeNode* root, int val) {
        if (val < root->val) {
            if (root->left == NULL)
                root->left = new TreeNode(val);
            else
                solve(root->left, val);
        } else {
            if (root->right == NULL)
                root->right = new TreeNode(val);
            else
                solve(root->right, val);
        }
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);

        solve(root, val);
        return root;
    }
};