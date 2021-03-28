// 删除二叉搜索树中的节点
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpcnds/

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 以node为根的子树中最小节点
    TreeNode* minimum(TreeNode* node) {
        if(node->left == nullptr) return node;

        return minimum(node->left);
    }

    TreeNode* removeMin(TreeNode* node) {
        if(node->left == nullptr) {
            TreeNode* rightNode = node->right;
            delete node;
            return rightNode;
        }

        node->left = removeMin(node->left);
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return nullptr;

        if(key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if(key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if(root->left == nullptr) {
                TreeNode* rightNode = root->right;
                delete root;
                return rightNode;
            }
            if(root->right == nullptr) {
                TreeNode* leftNode = root->left;
                delete root;
                return leftNode;
            }

            TreeNode* successor = new TreeNode(minimum(root->right)->val);
            successor->right = removeMin(root->right);
            successor->left = root->left;
            delete root;

            return successor;
        }

        return root;
    }
};