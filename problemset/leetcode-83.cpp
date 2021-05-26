// 83. 删除排序链表中的重复元素
// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/

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
        ListNode* toDel = pre->next;
        pre->next = toDel->next;
        delete toDel;
    }

public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* cur = head;

        while(cur->next != nullptr) {
            if(cur->val == cur->next->val) {
                deleteNext(cur);
            } else {
                cur = cur->next;
            }
        }

        return head;
    }
};