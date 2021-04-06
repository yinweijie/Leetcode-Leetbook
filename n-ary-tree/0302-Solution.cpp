// N 叉树的最大深度
// https://leetcode-cn.com/leetbook/read/n-ary-tree/x0t4zv/

#include <vector>

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
    int res = 0;

    void maxDepth(Node* node, int depth) {
        if(node == nullptr) return;

        if(node->children.size() == 0) {
            res = max(res, depth);
        }

        for(Node* child : node->children) {
            maxDepth(child, depth + 1);
        }
    }

public:
    int maxDepth(Node* root) {
        maxDepth(root, 1);

        return res;
    }
};