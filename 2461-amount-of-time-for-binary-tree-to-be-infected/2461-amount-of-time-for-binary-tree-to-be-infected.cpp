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

    int solve(TreeNode* target, unordered_map<TreeNode*, TreeNode*>& mp) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    spread = true;
                }
                if (curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    spread = true;
                }
                if (mp.find(curr) != mp.end() && !visited[mp[curr]]) {
                    q.push(mp[curr]);
                    visited[mp[curr]] = true;
                    spread = true;
                }
            }
            if (spread) ans++;
        }
        return ans;
    }

    TreeNode* getNode(int start, TreeNode* root) {
        if (!root) return NULL;
        if (root->val == start) return root;
        TreeNode* left = getNode(start, root->left);
        if (left) return left;
        return getNode(start, root->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mp;
        findParents(root, mp);
        TreeNode* target = getNode(start, root);
        return solve(target, mp);
    }
};
