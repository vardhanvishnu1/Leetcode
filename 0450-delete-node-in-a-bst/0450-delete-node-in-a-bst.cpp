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
    TreeNode* inordersuccessor(TreeNode* root) {
        TreeNode* suc = root->right;
        while (suc && suc->left) {
            suc = suc->left;
        }
        return suc;
    }

    void traverse(TreeNode* root, int key, TreeNode*& temp, TreeNode*& parent) {
        if (!root) return;
        if (root->left && root->left->val == key) {
            parent = root;
            temp = root->left;
            return;
        }
        if (root->right && root->right->val == key) {
            parent = root;
            temp = root->right;
            return;
        }
        traverse(root->left, key, temp, parent);
        traverse(root->right, key, temp, parent);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        // Case 1: Root itself is the node to delete
        if (root->val == key) {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            if (!root->left) {
                TreeNode* r = root->right;
                delete root;
                return r;
            }
            if (!root->right) {
                TreeNode* l = root->left;
                delete root;
                return l;
            }

            // Two children
            TreeNode* suc = inordersuccessor(root);
            root->val = suc->val;
            root->right = deleteNode(root->right, suc->val);
            return root;
        }

        // Case 2: Find the node and parent
        TreeNode* temp = nullptr;
        TreeNode* parent = nullptr;
        traverse(root, key, temp, parent);

        if (!temp) return root; // not found

        // Case 3: Leaf
        if (!temp->left && !temp->right) {
            if (parent->left == temp) parent->left = nullptr;
            else parent->right = nullptr;
            delete temp;
        }
        // Case 4: One child
        else if ((temp->left && !temp->right) || (!temp->left && temp->right)) {
            TreeNode* child = temp->left ? temp->left : temp->right;
            if (parent->left == temp) parent->left = child;
            else parent->right = child;
            delete temp;
        }
        // Case 5: Two children
        else {
            TreeNode* suc = inordersuccessor(temp);
            int val = suc->val;
            deleteNode(root, val);  // remove successor
            temp->val = val;
        }

        return root;
    }
};
