// 二叉树的前序遍历
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xeywh5/

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

public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;

        res.emplace_back(root->val);
        if(root->left) {
            preorderTraversal(root->left);
        }
        if(root->right) {
            preorderTraversal(root->right);
        }

        return res;
    }
};