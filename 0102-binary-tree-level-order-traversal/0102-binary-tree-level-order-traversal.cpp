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
void traverse(int level,TreeNode* root,vector<vector<int>>&ans){
    if(!root) return;
    ans[level].push_back(root->val);
    traverse(level+1,root->left,ans);
    traverse(level+1,root->right,ans);
}
int lvl(TreeNode* root){
    if(!root) return 0;
    int left = 1+lvl(root->left);
    int right = 1+lvl(root->right);
    return max(left,right);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = lvl(root);
        vector<vector<int>>ans(n);
        traverse(0,root,ans);
        return ans;
    }
};