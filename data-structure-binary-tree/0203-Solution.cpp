// 对称二叉树
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoxzgv/

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
    // p和q为根的子树是否是镜像
    bool check(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if(p == nullptr || q == nullptr) return false;

        return p->val == q->val &&
                check(p->right, q->left) &&
                check(p->left, q->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};