// 21. 合并两个有序链表
// https://leetcode-cn.com/problems/merge-two-sorted-lists/

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;

        while(l1 || l2) {
            if(l1 == nullptr) {
                tail->next = l2;
                break;
            } else if(l2 == nullptr) {
                tail->next = l1;
                break;
            } else {
                if(l1->val < l2->val) {
                    tail->next = l1;
                    tail = l1;
                    l1 = l1->next;
                } else {
                    tail->next = l2;
                    tail = l2;
                    l2 = l2->next;
                }
            }
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};