// 最接近的二叉搜索树值
// https://leetcode-cn.com/leetbook/read/binary-search/xedyk5/

#include <limits>
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
    double dist = numeric_limits<double>::max();
    int res;

public:
    int closestValue(TreeNode* root, double target) {
        if(root == nullptr) return 0;

        if(dist > abs(target - root->val)) {
            dist = abs(target - root->val);
            res = root->val;
        }

        if(target > (double)root->val) {
            closestValue(root->right, target);
        } else {
            closestValue(root->left, target);
        }

        return res;
    }
};