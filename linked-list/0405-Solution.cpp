// 回文链表
// https://leetcode-cn.com/leetbook/read/linked-list/fov6t/

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
    bool isPalindrome(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1, head);
        ListNode* pre = nullptr;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;

        if(head == nullptr) return false;
        if(head->next == nullptr) return true;

        while(fast && fast->next) {
            fast = fast->next->next;

            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        // 奇数个节点
        if(fast == nullptr) {
            slow = slow->next;

        } else { // 偶数个节点
            ListNode* next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }

        while(pre != dummyHead && slow != nullptr) {
            if(pre->val != slow->val) {
                return false;
            }
            pre = pre->next;
            slow = slow->next;

            if(pre == dummyHead && slow == nullptr) {
                return true;
            }
        }

        return false;
    }
};