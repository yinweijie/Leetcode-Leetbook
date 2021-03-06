// 二叉树的最近公共祖先
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xopaih/

#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode* res;

    // node为根的子树包含p或者q
    bool fx(TreeNode* node, TreeNode* p, TreeNode* q) {
        if(node == nullptr) return false;

        bool fLeft = fx(node->left, p, q);
        bool fRight = fx(node->right, p, q);

        if((fLeft && fRight) || ((node == p || node == q) && (fLeft || fRight))) {
            res = node;
        }

        return fLeft || fRight || node == p || node == q;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        fx(root, p, q);
        return res;
    }
};