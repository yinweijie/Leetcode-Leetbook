// 扁平化多级双向链表
// https://leetcode-cn.com/leetbook/read/linked-list/fw8v5/

#include <utility>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

// 参考：https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/solution/java-dai-ma-jian-ji-yi-dong-si-lu-qing-x-j7rm/
class Solution {
private:
    // <head, tail>
    pair<Node*, Node*> dfs(Node* node) {
        if(node == nullptr) return make_pair(nullptr, nullptr);

        Node* cur = node;
        Node* pre = nullptr;
        while(cur) {
            if(cur->child) {
                Node* child = cur->child;
                cur->child = nullptr;

                auto[head, tail] = dfs(child);

                if(cur->next)
                    cur->next->prev = tail;
                tail->next = cur->next;
                cur->next = head;
                head->prev = cur;
            }
            pre = cur;
            cur = cur->next;
        }

        return make_pair(node, pre);
    }

public:
    Node* flatten(Node* head) {
        if(head == nullptr) return nullptr;
        auto[res, tail] = dfs(head);

        return res;
    }
};