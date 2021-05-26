// 203. 移除链表元素
// https://leetcode-cn.com/problems/remove-linked-list-elements/

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
private:
    void deleteNext(ListNode* pre) {
        if(pre->next == nullptr) return;

        ListNode* toDel = pre->next;
        pre->next = toDel->next;
        delete toDel;
    }
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = dummyHead;

        while(pre->next != nullptr) {
            if(pre->next->val == val) {
                deleteNext(pre);
            } else {
                pre = pre->next;
            }
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};