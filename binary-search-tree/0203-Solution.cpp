// 二叉搜索树迭代器
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xpg4qe/

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

class BSTIterator {
private:
    queue<TreeNode*> q;

    void inorderSave(TreeNode* node) {
        if(node == nullptr) return;

        inorderSave(node->left);
        q.emplace(node);
        inorderSave(node->right);
    }

public:
    BSTIterator(TreeNode* root) {
        inorderSave(root);
    }
    
    int next() {
        int res = q.front()->val;
        q.pop();
        return res;
    }
    
    bool hasNext() {
        return q.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */