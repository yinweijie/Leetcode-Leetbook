// 二叉树的后序遍历
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xebrb2/

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

    void _postorderTraversal(TreeNode* node) {
        if(node == nullptr) return;

        if(node->left) {
            _postorderTraversal(node->left);
        }
        if(node->right) {
            _postorderTraversal(node->right);
        }
        res.emplace_back(node->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        _postorderTraversal(root);

        return res;
    }
};