// 序列化和反序列化 N 叉树
// https://leetcode-cn.com/leetbook/read/n-ary-tree/x08gkj/

#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Codec {
private:
    void serialize(Node* node, string& str) {
        if(node == nullptr) {
            str += "null,";
            return;
        }

        str += to_string(node->val) + ",";
        str += to_string(node->children.size()) + ",";
        for(Node* child : node->children) {
            serialize(child, str);
        }
    }

    Node* deserialize(queue<string>& q) {
        if(q.front() == "null") return nullptr;

        Node* node = new Node(stoi(q.front()));
        q.pop();
        int sz = stoi(q.front());
        q.pop();

        for(int i = 0; i < sz; i++) {
            node->children.emplace_back(deserialize(q));
        }

        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        string str = "";
        serialize(root, str);
        return str;
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        queue<string> q;

        char* token = strtok(data.data(), ",");
        while(token) {
            q.emplace(token);
            token = strtok(NULL, ",");
        }

        return deserialize(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));