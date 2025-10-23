/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int val,TreeNode* prev){
        if(!root){
            if(val>prev->val) prev->right = new TreeNode(val);
            else prev->left = new TreeNode(val);
            return;
        }
        if(val>root->val) solve(root->right,val,root);
        else solve(root->left,val,root);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* prev = NULL;
        if(!root){
            return new TreeNode(val);
        }
        solve(root,val,prev);
        return root;
    }
};