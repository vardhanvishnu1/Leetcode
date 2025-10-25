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
void solve(TreeNode* root,TreeNode*& prev,TreeNode*& first,TreeNode*& middle,TreeNode* &last){
    if(!root) return;
    solve(root->left,prev,first,middle,last);
    if(prev&&root->val<prev->val){
        if(!first){
            first=prev;
            middle = root;
        }
        else{
            last = root;
        }
    }
    prev = root;
    solve(root->right,prev,first,middle,last);
    return;
}
    void recoverTree(TreeNode* root) {
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* middle = NULL;
        TreeNode* last = NULL;
        solve(root,prev,first,middle,last);
        if(!last) swap(first->val,middle->val);
        else swap(first->val,last->val);
        return;
    }
};