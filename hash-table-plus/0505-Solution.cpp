// 寻找重复的子树
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x70j7e/

#include <vector>
#include <string>
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
    string serialize(TreeNode* node) {
        if(node == nullptr) return "null,";

        string str = to_string(node->val) + "," + serialize(node->left) + serialize(node->right);
        hashMap[str]++;

        if(hashMap[str] == 2) {
            res.emplace_back(node);
        }

        return str;
    }

    unordered_map<string, int> hashMap;
    vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        serialize(root);

        return res;
    }
};