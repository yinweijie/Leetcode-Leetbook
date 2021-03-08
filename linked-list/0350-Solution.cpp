// 删除链表的倒数第N个节点
// https://leetcode-cn.com/leetbook/read/linked-list/jf1cc/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(-1, head);

        ListNode *p = dummyHead, *q = dummyHead;
        for(int i = 0; i < n + 1; i++) {
            q = q->next;
        }

        while(q != nullptr) {
            p = p->next;
            q = q->next;
        }

        // remove p->next
        ListNode* toDel = p->next;
        p->next = toDel->next;
        delete toDel;

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};