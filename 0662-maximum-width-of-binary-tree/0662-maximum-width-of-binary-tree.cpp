class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int sz = q.size();

            long long mn = q.front().second;
            long long first, last;

            for (int i = 0; i < sz; i++) {
                auto [node, idx] = q.front();
                q.pop();

                idx -= mn; // prevent overflow

                if (i == 0) first = idx;
                if (i == sz - 1) last = idx;

                if (node->left)
                    q.push({node->left, 2 * idx + 1});

                if (node->right)
                    q.push({node->right, 2 * idx + 2});
            }

            ans = max(ans, last - first + 1);
        }

        return (int)ans;
    }
};