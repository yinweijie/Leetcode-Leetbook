// 二叉树的最大深度
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoh1zg/

#include <algorithm>

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
    int res = 0;

    void maxDepth(TreeNode* node, int depth) {
        if(node == nullptr) return;

        if(node->left == nullptr && node->right == nullptr) {
            res = max(res, depth);
        }

        maxDepth(node->left, depth + 1);
        maxDepth(node->right, depth + 1);
    }
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        maxDepth(root, depth + 1);
        return res;
    }
};