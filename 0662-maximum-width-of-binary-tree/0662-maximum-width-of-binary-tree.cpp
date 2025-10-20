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
    void dfs(TreeNode* root, unsigned long long row, unsigned long long col, 
             unordered_map<unsigned long long, vector<unsigned long long>>& mp) {
        if (!root) return;
        mp[row].push_back(col);
        dfs(root->left, row + 1, 2 * col + 1, mp);
        dfs(root->right, row + 1, 2 * col + 2, mp);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        unordered_map<unsigned long long, vector<unsigned long long>> mp;
        dfs(root, 0, 0, mp);

        unsigned long long ans = 0;
        for (auto& [row, cols] : mp) {
            ans = max(ans, cols.back() - cols.front() + 1);
        }
        return (int)ans;
    }
};
