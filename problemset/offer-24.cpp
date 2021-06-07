// 剑指 Offer 24. 反转链表
// https://leetcode-cn.com/problems/fan-zhuan-lian-biao-lcof/

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    ListNode* reverseListR(ListNode* node) {
        if(node == nullptr) return nullptr;
        if(node->next == nullptr) mHead = node;

        ListNode* lastNode = reverseListR(node->next);
        if(lastNode) lastNode->next = node;

        node->next = nullptr;

        return node;
    }

    ListNode* mHead;

public:
    ListNode* reverseList(ListNode* head) {
        reverseListR(head);

        return mHead;
    }
};