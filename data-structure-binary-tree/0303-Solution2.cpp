// 填充每个节点的下一个右侧节点指针
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoo0ts/

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

// 参考：https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/dong-hua-yan-shi-san-chong-shi-xian-116-tian-chong/
class Solution {
private:
    void dfs(Node* root) {
        if(root == nullptr) return;

        Node* left = root->left;
        Node* right = root->right;
        while(left != nullptr) {
            left->next = right;
            left = left->right;
            right = right->left;
        }

        dfs(root->left);
        dfs(root->right);
    }
public:
    Node* connect(Node* root) {
        if(root == nullptr) return nullptr;
        dfs(root);
        return root;
    }
};