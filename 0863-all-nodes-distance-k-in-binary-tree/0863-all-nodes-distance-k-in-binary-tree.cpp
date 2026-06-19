class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur->left) {
                parent[cur->left] = cur;
                q.push(cur->left);
            }

            if (cur->right) {
                parent[cur->right] = cur;
                q.push(cur->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root);

        queue<TreeNode*> q;
        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        int dist = 0;

        while (!q.empty()) {
            int sz = q.size();

            if (dist == k) {
                vector<int> ans;
                while (!q.empty()) {
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return ans;
            }

            while (sz--) {
                TreeNode* cur = q.front();
                q.pop();

                if (cur->left && !vis.count(cur->left)) {
                    vis.insert(cur->left);
                    q.push(cur->left);
                }

                if (cur->right && !vis.count(cur->right)) {
                    vis.insert(cur->right);
                    q.push(cur->right);
                }

                if (parent.count(cur) && !vis.count(parent[cur])) {
                    vis.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }

            dist++;
        }

        return {};
    }
};