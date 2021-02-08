// 二叉树的中序遍历
// https://leetcode-cn.com/leetbook/read/queue-stack/gnq5i/

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

// 递归版本
class Solution {
private:
    vector<int> res;

    void _inorderTraversal(TreeNode* node) {
        if(node == nullptr) return;

        _inorderTraversal(node->left);
        res.emplace_back(node->val);
        _inorderTraversal(node->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        _inorderTraversal(root);

        return res;
    }
};

int main() {

    return 0;
}