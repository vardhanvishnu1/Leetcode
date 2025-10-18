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
 void levelOrderTraversal(TreeNode* root,vector<vector<int>>&ans){
        queue<TreeNode*>q;
        q.push(root);             
        while(!q.empty()){
            vector<int>level;
            int size = q.size();
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ans.push_back(level);
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        levelOrderTraversal(root,ans);
        for(int i=0;i<ans.size();i++){
            if(i&1){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};