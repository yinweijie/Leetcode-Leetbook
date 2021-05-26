// 876. 链表的中间结点
// https://leetcode-cn.com/problems/middle-of-the-linked-list/

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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        if(head == nullptr || head->next == nullptr) return head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};