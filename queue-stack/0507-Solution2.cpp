// 二叉树的中序遍历
// https://leetcode-cn.com/leetbook/read/queue-stack/gnq5i/

#include <vector>
#include <stack>
#include <string>
#include <cassert>

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

// 非递归版本
class Solution {
private:
    struct Command {
        string name; // call, print
        TreeNode* node;

        Command(const string& name_, TreeNode* node_) : name(name_), node(node_) { }
    };

public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<Command> commands;
        vector<int> res;

        if(root == nullptr) return res;

        commands.emplace(Command("call", root));

        while(!commands.empty()) {
            Command cmd = commands.top();
            commands.pop();

            if(cmd.name == "print") {
                res.emplace_back(cmd.node->val);
            } else {
                assert(cmd.name == "call");

                if(cmd.node == nullptr) {
                    continue;
                }

                commands.emplace(Command("call", cmd.node->right));
                commands.emplace(Command("print", cmd.node));
                commands.emplace(Command("call", cmd.node->left));
            }
        }

        return res;
    }
};

int main() {

    return 0;
}