// 328. 奇偶链表
// https://leetcode-cn.com/problems/odd-even-linked-list/

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
        ListNode* oddHead = new ListNode(-1);
        ListNode* oddTail = oddHead;
        ListNode* evenHead = new ListNode(-1);
        ListNode* evenTail = evenHead;

        int index = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            if(index % 2 == 0) {
                evenTail->next = cur;
                evenTail = evenTail->next;
            } else {
                oddTail->next = cur;
                oddTail = oddTail->next;
            }

            index++;
            cur = cur->next;
        }

        // take care !!!
        evenTail->next = nullptr;
        oddTail->next = nullptr;

        evenTail->next = oddHead->next;
        ListNode* res = evenHead->next;

        delete oddHead;
        delete evenHead;

        return res;
    }
};

int main() {
    ListNode* head = new ListNode(1);
    ListNode* node1 = new ListNode(2);
    ListNode* node2 = new ListNode(3);
    ListNode* node3 = new ListNode(4);
    ListNode* node4 = new ListNode(5);

    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    Solution().oddEvenList(head);

    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}