// 环形链表 II
// https://leetcode-cn.com/leetbook/read/linked-list/jjhf6/

#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                ListNode* ptr = head;

                while(slow != ptr) {
                    ptr = ptr->next;
                    slow = slow->next;
                }

                return ptr;
            }
        }

        return nullptr;
    }
};