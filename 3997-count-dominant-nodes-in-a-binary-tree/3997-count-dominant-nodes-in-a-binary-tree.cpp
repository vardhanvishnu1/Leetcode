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
    int solve(int& ans,TreeNode* root){
        if(!root) return -1;
        int lmax = solve(ans,root->left);
        int rmax = solve(ans,root->right);
        int mx = max({root->val,lmax,rmax});
        if(root->val==mx) ans++;
        return mx;
    }
    int countDominantNodes(TreeNode* root) {
        int ans = 0;
        solve(ans,root);
        return ans;
    }
};