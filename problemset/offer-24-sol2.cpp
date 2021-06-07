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
        if(node->next == nullptr) return node;

        ListNode* newHead = reverseListR(node->next);

        node->next->next = node;
        node->next = nullptr;

        return newHead;
    }


public:
    ListNode* reverseList(ListNode* head) {
        return reverseListR(head);
    }
};