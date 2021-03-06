// 填充每个节点的下一个右侧节点指针 II
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xorvud/

#include <queue>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;

        queue<Node*> q;
        q.emplace(root);

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                Node* node = q.front();
                q.pop();
                if(i == sz - 1) {
                    node->next = nullptr;
                } else {
                    node->next = q.front();
                }

                if(node->left) q.emplace(node->left);
                if(node->right) q.emplace(node->right);
            }
        }

        return root;
    }
};