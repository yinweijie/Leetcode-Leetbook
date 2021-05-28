// 2. 两数相加
// https://leetcode-cn.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* tail = dummyHead;

        int flag = 0;
        while(l1 || l2) {
            int l1Num = (l1 != nullptr) ? l1->val : 0;
            int l2Num = (l2 != nullptr) ? l2->val : 0;

            int sum = l1Num + l2Num + flag;

            int digit = 0;
            if(sum >= 10) {
                digit = sum - 10;
                flag = 1;
            } else {
                digit = sum;
                flag = 0;
            }

            tail->next = new ListNode(digit);
            tail = tail->next;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
        }
        
        if(flag == 1) {
            tail->next = new ListNode(1);
            tail = tail->next;
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};