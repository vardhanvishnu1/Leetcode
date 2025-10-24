
class Solution {
public:
void traverse(TreeNode* root,vector<int>&ans){
    if(root==NULL) return;
        traverse(root->left,ans);
        ans.push_back(root->val);
        traverse(root->right,ans);
}
    bool isValidBST(TreeNode* root) {
        vector<int>ans;
        traverse(root,ans);
        for(int i =1;i<ans.size();i++){
            if(ans[i]<=ans[i-1]) return false;
        }return true;  
    }
};