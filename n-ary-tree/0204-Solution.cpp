// N 叉树的层序遍历
// https://leetcode-cn.com/leetbook/read/n-ary-tree/x0if1e/

#include <vector>
#include <queue>

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

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;

        if(root == nullptr) return res;

        q.emplace(root);
        int idx = 0;
        while(!q.empty()) {
            int sz = q.size();

            res.emplace_back(vector<int>());
            for(int i = 0; i < sz; i++) {
                for(Node* child : q.front()->children) {
                    q.emplace(child);
                }

                res[idx].emplace_back(q.front()->val);
                q.pop();
            }
            idx++;
        }

        return res;
    }
};