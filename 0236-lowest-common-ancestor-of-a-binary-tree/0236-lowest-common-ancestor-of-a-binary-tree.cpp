/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool find_path(vector<TreeNode*>&p,TreeNode* root, TreeNode* x){
    if(!root) return false;
    p.push_back(root);
    if(root==x) return true;
    if(find_path(p,root->left,x)||
    find_path(p,root->right,x)) return true;
    p.pop_back();
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1;
        vector<TreeNode*>p2;
        find_path(p1,root,p);
        find_path(p2,root,q);
        int i=0,j=0;
        TreeNode* ans = root;
        while(i < p1.size() && j < p2.size()){
            if(p1[i]==p2[j]) ans = p1[i];
            else break;
            i++;j++;
        }
        return ans;
    }
};