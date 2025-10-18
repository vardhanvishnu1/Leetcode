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
    void traverse(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>& mp) {
        if (!root) return;
        // store (row, value)
        mp[col].push_back({row, root->val});
        traverse(root->left, row + 1, col - 1, mp);
        traverse(root->right, row + 1, col + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp; // col -> [(row, val)]
        traverse(root, 0, 0, mp);

        vector<vector<int>> ans;
        for (auto& [col, nodes] : mp) {
            // sort by row first, then by value
            sort(nodes.begin(), nodes.end(), [](auto &a, auto &b) {
                if (a.first == b.first) return a.second < b.second;
                return a.first < b.first;
            });

            vector<int> colVals;
            for (auto &p : nodes) colVals.push_back(p.second);
            ans.push_back(colVals);
        }
        return ans;
    }
};
