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
void traverse(vector<int>&ans,TreeNode* root, int k,int node){
    if(!root) return;
    traverse(ans,root->left,k,node+1);
    ans.push_back(root->val);
    traverse(ans,root->right,k,node+1);

}
    int kthSmallest(TreeNode* root, int k) {
        vector<int>ans;
        traverse(ans,root,k,0);
        return ans[k-1];
    }
};