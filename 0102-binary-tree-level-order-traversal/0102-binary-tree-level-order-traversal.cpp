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
    void levelOrderTraversal(TreeNode* root,vector<vector<int>>&ans,int level){
        if(!root) return; 
        if(ans.size()==level) ans.push_back({});
        ans[level].push_back(root->val);
        levelOrderTraversal(root->left,ans,level+1);
        levelOrderTraversal(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        levelOrderTraversal(root,ans,0);
        return ans;
    }
};