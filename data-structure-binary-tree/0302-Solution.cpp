// 从前序与中序遍历序列构造二叉树
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xoei3r/

#include <vector>
#include <unordered_map>

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
    unordered_map<int, int> mp;
    vector<int> _preorder;

    TreeNode* buildTree(int preStart, int preEnd, int inStart, int inEnd) {
        if(preStart > preEnd || inStart > inEnd) return nullptr;

        auto[inNumber, inIndex] = *mp.find(_preorder[preStart]);
        TreeNode* node = new TreeNode(inNumber);
        node->left = buildTree(preStart + 1, preStart + inIndex - inStart, inStart, inIndex - 1);
        node->right = buildTree(preStart + inIndex - inStart + 1, preEnd, inIndex + 1, inEnd);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        _preorder = preorder;

        return buildTree(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};