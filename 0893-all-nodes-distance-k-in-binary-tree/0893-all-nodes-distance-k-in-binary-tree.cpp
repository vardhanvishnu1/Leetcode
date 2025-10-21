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
    void findParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                mp[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                mp[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    void solve(TreeNode* target, int k, unordered_map<TreeNode*, TreeNode*>& mp, vector<int>& ans) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;

        q.push(target);
        visited[target] = true;

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break;  // Stop once we reach level k

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();

                // Left child
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }

                // Right child
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }

                // Parent node
                if (mp.find(curr) != mp.end() && !visited[mp[curr]]) {
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                }
            }
            dist++;  // After processing one level
        }

        // Collect all nodes exactly k distance away
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp;
        vector<int> ans;
        findParents(root, mp);
        solve(target, k, mp, ans);
        return ans;
    }
};
