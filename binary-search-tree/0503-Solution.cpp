// 将有序数组转换为二叉搜索树
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xm5go5/

#include <vector>

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
    TreeNode* buildTree(vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        if(l == r) return new TreeNode(nums[l]);

        int mid = l + (r - l) / 2;

        TreeNode* node = new TreeNode(nums[mid]);
        node->left = buildTree(nums, l, mid - 1);
        node->right = buildTree(nums, mid + 1, r);

        return node;
    }

public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
};