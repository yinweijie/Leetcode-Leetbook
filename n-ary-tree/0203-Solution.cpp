// N 叉树的后序遍历
// https://leetcode-cn.com/leetbook/read/n-ary-tree/x0i5yi/

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
    vector<int> postorder(Node* root) {
        if(root == nullptr) return res;

        for(Node* child : root->children) {
            postorder(child);
        }
        res.emplace_back(root->val);

        return res;
    }
};