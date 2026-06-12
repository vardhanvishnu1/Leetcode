class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();

                // first node at level = rightmost
                if (i == 0) ans.push_back(node->val);

                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
        }

        return ans;
    }
};