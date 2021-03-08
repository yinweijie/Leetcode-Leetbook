// 移除链表元素
// https://leetcode-cn.com/leetbook/read/linked-list/f9izv/

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1, head);
        if(head == nullptr) return nullptr;

        ListNode* pre = dummyHead;
        while(pre->next != nullptr) {
            if(pre->next->val == val) {
                ListNode* toDel = pre->next;
                pre->next = toDel->next;
                delete toDel;
            } else {
                pre = pre->next;
            }
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;
        return res;
    }
};