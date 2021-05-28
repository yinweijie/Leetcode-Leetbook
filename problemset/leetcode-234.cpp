// 234. 回文链表

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
        if(head == nullptr || head->next == nullptr) return true;

        ListNode* fast = head;
        ListNode* slow = head;

        // 快慢指针找到中间节点
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* flag = slow;

        ListNode* pre = nullptr;
        ListNode* cur = head;

        // 从中间断开
        while(cur != flag) {
            // 反转链表
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        // 对比两个链表
        ListNode* start1 = pre;
        ListNode* start2 = (fast == nullptr) ? flag : flag->next;

        while(start1 != nullptr && start2 != nullptr) {
            if(start1->val != start2->val) return false;

            start1 = start1->next;
            start2 = start2->next;
        }

        return true;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(1);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;

    Solution().isPalindrome(head);

    return 0;
}