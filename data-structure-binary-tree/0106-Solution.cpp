// 二叉树的层序遍历
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xefh1i/

#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;

        if(root == nullptr) return res;

        q.emplace(make_pair(root, 0));
        while(!q.empty()) {
            auto[node, level] = q.front();
            q.pop();

            if(level == res.size()) {
                res.emplace_back(vector<int>());
            }

            res[level].emplace_back(node->val);
            if(node->left)
                q.emplace(make_pair(node->left, level + 1));
            if(node->right)
                q.emplace(make_pair(node->right, level + 1));
        }

        return res;
    }
};