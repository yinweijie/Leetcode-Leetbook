// 二叉树的中序遍历
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xecaj6/

#include <vector>
#include <string>
#include <stack>

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
    struct Command {
        string name; // "call", "print"
        TreeNode* node;
    };

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<Command> stk;
        if(root == nullptr) return res;

        stk.emplace(Command{"call", root});
        while(!stk.empty()) {
            Command cmd = stk.top();
            stk.pop();

            if(cmd.name == "print") {
                res.emplace_back(cmd.node->val);
            } else {
                if(cmd.node->right)
                    stk.emplace(Command{"call", cmd.node->right});
                stk.emplace(Command{"print", cmd.node});
                if(cmd.node->left)
                    stk.emplace(Command{"call", cmd.node->left});
            }
        }

        return res;
    }
};