// 奇偶链表
// https://leetcode-cn.com/leetbook/read/linked-list/fe0kj/

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
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr) return nullptr;

        ListNode* evenHead = head->next;
        ListNode* evenCur = evenHead;
        ListNode* oddCur = head;
        while(evenCur && evenCur->next) {
            oddCur->next = evenCur->next;
            oddCur = oddCur->next;
            evenCur->next = oddCur->next;
            evenCur = evenCur->next;
        }

        oddCur->next = evenHead;
        return head;
    }
};