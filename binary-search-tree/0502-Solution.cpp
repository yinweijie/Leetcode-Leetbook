// 平衡二叉树
// https://leetcode-cn.com/leetbook/read/introduction-to-data-structure-binary-search-tree/xmx4r7/

#include <algorithm>
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
    unordered_map<TreeNode*, int> hashMap;

    int height(TreeNode* node) {
        if(node == nullptr) return 0;

        if(hashMap.find(node) != hashMap.end()) {
            return hashMap[node];
        }

        // 对于数据规模比较小的测试用例，哈希表体现不出优势，所以这里虽然优化了，但是
        // leetcode上的测试效率反而比不优化低。主要是哈希表的查表与扩容耗时较大。
        int retHeight = max(height(node->left), height(node->right)) + 1;
        hashMap[node] = retHeight;
        return retHeight;
    }

public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        return abs(height(root->left) - height(root->right)) <= 1 &&
                isBalanced(root->left) && isBalanced(root->right);
    }
};

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution().isBalanced(root);

    return 0;
}