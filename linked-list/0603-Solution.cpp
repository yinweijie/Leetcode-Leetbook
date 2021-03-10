// 两数相加
// https://leetcode-cn.com/leetbook/read/linked-list/fv6w7/

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
        int digit = 0;
        int flag = 0; // 有进位时为1，无进位为0

        ListNode* pre = dummyHead;
        while(l1 != nullptr || l2 != nullptr) {
            int num1 = l1 == nullptr ? 0 : l1->val;
            int num2 = l2 == nullptr ? 0 : l2->val;

            digit = num1 + num2 + flag;
            flag = 0;
            if(digit >= 10) {
                digit = digit - 10;
                flag = 1;
            }

            pre->next = new ListNode(digit);
            pre = pre->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        if(flag == 1) {
            pre->next = new ListNode(1);
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};