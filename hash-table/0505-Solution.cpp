// 寻找重复的子树
// https://leetcode-cn.com/leetbook/read/hash-table/xxm0i6/

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
    //           <tree, count>
    unordered_map<string, int> hashMap;
    vector<TreeNode*> resVec;

    string collect(TreeNode* node) {
        if(node == nullptr) return "#";

        string resStr = to_string(node->val) + "," + collect(node->left) + "," + collect(node->right);

        hashMap[resStr]++;
        if(hashMap[resStr] == 2) {
            resVec.emplace_back(node);
        }

        return resStr;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == nullptr) return resVec;

        collect(root);

        return resVec;
    }
};