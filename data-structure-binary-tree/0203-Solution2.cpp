// 对称二叉树
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoxzgv/

#include <queue>

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
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;

        q1.emplace(root);
        q2.emplace(root);
        while(!q1.empty() && !q2.empty()) {
            TreeNode* node1 = q1.front();
            TreeNode* node2 = q2.front();
            q1.pop();
            q2.pop();

            if(node1 == nullptr && node2 != nullptr) {
                return false;
            } else if(node1 != nullptr && node2 == nullptr) {
                return false;
            }

            if(node1 != nullptr && node2 != nullptr && node1->val != node2->val) {
                return false;
            }
            if(node1) {
                q1.emplace(node1->left);
                q1.emplace(node1->right);
            }
            if(node2) {
                q2.emplace(node2->right);
                q2.emplace(node2->left);
            }
        }

        return true;
    }
};