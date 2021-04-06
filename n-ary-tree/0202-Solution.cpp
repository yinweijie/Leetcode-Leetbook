// N 叉树的前序遍历
// https://leetcode-cn.com/leetbook/read/n-ary-tree/x0locc/

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
    vector<int> res;

public:
    vector<int> preorder(Node* root) {
        if(root == nullptr) return res;

        res.emplace_back(root->val);
        for(Node* child : root->children) {
            preorder(child);
        }

        return res;
    }
};