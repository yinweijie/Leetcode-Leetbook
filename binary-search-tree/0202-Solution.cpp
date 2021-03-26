// 验证二叉搜索树
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpkc6i/

#include <limits>

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
    bool isBounded(TreeNode* node, long long upper, long long lower) {
        if(node == nullptr) return true;

        if(node->val >= upper || node->val <= lower) {
            return false;
        }

        return isBounded(node->left, node->val, lower) &&
                isBounded(node->right, upper, node->val);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isBounded(root, numeric_limits<long long>::max(), numeric_limits<long long>::min());
    }
};

int main() {
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    Solution().isValidBST(root);
    return 0;
}