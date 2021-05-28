// 206. 反转链表
// https://leetcode-cn.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;

        while(cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }

        return pre;
    }
};