// 二叉树的中序遍历
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xecaj6/

#include <vector>

using namespace std;

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
    vector<int> res;

    void _inorderTraversal(TreeNode* node) {
        if(node == nullptr) return;

        if(node->left) {
            _inorderTraversal(node->left);
        }
        res.emplace_back(node->val);
        if(node->right) {
            _inorderTraversal(node->right);
        }
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        _inorderTraversal(root);

        return res;
    }
};