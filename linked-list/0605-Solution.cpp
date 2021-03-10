// 复制带随机指针的链表
// https://leetcode-cn.com/leetbook/read/linked-list/fdi26/

#include <vector>
#include <unordered_map>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
private:
    unordered_map<Node*, Node*> mp;

public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;

        if(mp.find(head) != mp.end()) {
            return mp[head];
        }

        Node* node = new Node(head->val);
        mp[head] = node;

        node->next = copyRandomList(head->next);
        node->random = copyRandomList(head->random);

        return node;
    }
};