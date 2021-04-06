// N 叉树的前序遍历
// https://leetcode-cn.com/leetbook/read/n-ary-tree/x0locc/

#include <vector>
#include <string>
#include <stack>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    struct Command {
        string name; // "call", "print"
        Node* node;
    };

public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Command> commands;

        if(root == nullptr) return res;

        commands.emplace(Command {"call", root});
        while(commands.size() > 0) {
            Command cmd = commands.top();
            commands.pop();

            if(cmd.name == "print") {
                res.emplace_back(cmd.node->val);
            } else {
                for(auto it = cmd.node->children.rbegin(); it != cmd.node->children.rend(); it++) {
                    commands.emplace(Command {"call", *it});
                }
                commands.emplace(Command {"print", cmd.node});
            }
        }

        return res;
    }
};