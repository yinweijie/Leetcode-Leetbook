// 克隆图
// https://leetcode-cn.com/leetbook/read/queue-stack/gmcr6/

#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        if(visited.find(node) != visited.end()) {
            return visited[node];
        }

        Node* newNode = new Node(node->val);
        visited[node] = newNode;

        for(auto& neighborNode : node->neighbors) {
            newNode->neighbors.emplace_back(cloneGraph(neighborNode));
        }

        return newNode;
    }
};