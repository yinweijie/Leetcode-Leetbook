// 旋转链表
// https://leetcode-cn.com/leetbook/read/linked-list/f00a2/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;

        ListNode* dummyHead = new ListNode(-1, head);

        ListNode* pre = dummyHead;
        int cnt = 0;
        while(pre->next) {
            cnt++;
            pre = pre->next;
        }

        pre->next = head;

        pre = dummyHead;
        for(int i = 0; i < cnt - k % cnt; i++) {
            pre = pre->next;
        }

        dummyHead->next = pre->next;
        pre->next = nullptr;

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};