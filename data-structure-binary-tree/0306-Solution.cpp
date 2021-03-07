// 二叉树的序列化与反序列化
// https://leetcode-cn.com/leetbook/read/data-structure-binary-tree/xomr73/

#include <string>
#include <cstring>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void serialize(TreeNode* node, string& str) {
        if(node == nullptr) {
            str += "NULL,";
            return;
        }

        str += to_string(node->val) + ",";
        serialize(node->left, str);
        serialize(node->right, str);
    }

    TreeNode* deserialize(queue<string>& q) {
        if(q.front() == "NULL") {
            q.pop();
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(q.front()));
        q.pop();
        node->left = deserialize(q);
        node->right = deserialize(q);

        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        serialize(root, str);
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        char* token = strtok(data.data(), ",");
        while(token) {
            q.emplace(string(token));
            token = strtok(NULL, ",");
        }

        return deserialize(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));