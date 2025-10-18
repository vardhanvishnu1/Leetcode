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
        bool flag = true;
        while(!q.empty()){
            int size = q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                int idx;
                if (flag) idx = i;
                else idx = size - i - 1;
                level[idx]=(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            flag = !flag;
            ans.push_back(level);
        }
        return;
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>ans;
        levelOrderTraversal(root,ans);
        return ans;
    }
};