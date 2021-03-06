// 从中序与后序遍历序列构造二叉树
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xo98qt/

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

// 参考：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/solution/tu-jie-gou-zao-er-cha-shu-wei-wan-dai-xu-by-user72/
class Solution {
private:
    unordered_map<int, int> mp; // <number, index>
    vector<int> _postorder;

    TreeNode* buildTree(int iStart, int iEnd, int pStart, int pEnd) {
        if(iStart > iEnd || pStart > pEnd) return nullptr;

        auto[iNumber, iIndex] = *mp.find(_postorder[pEnd]);
        TreeNode* node = new TreeNode(iNumber);
        node->left = buildTree(iStart, iIndex - 1, pStart, pStart + iIndex - iStart - 1);
        node->right = buildTree(iIndex + 1, iEnd, pStart + iIndex - iStart, pEnd - 1);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        _postorder = postorder;

        TreeNode* res = buildTree(0, inorder.size() - 1, 0, postorder.size() - 1);
        return res;
    }
};