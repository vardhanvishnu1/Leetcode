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
int maxDepth(TreeNode* root){
    if(!root) return 0;
    int left = 1  + maxDepth(root->left);
    int right = 1  + maxDepth(root->right);
    return max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int left = 0;
        if(root->left) left = maxDepth(root->left);
        int right = 0;
        if(root->right) right = maxDepth(root->right);
        int a = left+right;
        int b =  diameterOfBinaryTree(root->left);
        int c =  diameterOfBinaryTree(root->right);
        return max(a,max(b,c));
    }
};