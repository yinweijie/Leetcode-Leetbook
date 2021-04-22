// 147. 对链表进行插入排序
// https://leetcode-cn.com/leetbook/read/sort-algorithms/euvypr/

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1, head);

        ListNode* putNode = head->next;
        ListNode* putNodePre = head;
        while(putNode) {
            ListNode* pre = dummyHead;
            ListNode* cur = dummyHead->next;
            ListNode* putNodeCpy = putNode;
            putNode = putNode->next;

            while(cur != putNodeCpy && cur->val < putNodeCpy->val) {
                pre = pre->next;
                cur = cur->next;
            }

            if(cur == putNodeCpy) {
                putNodePre = putNodePre->next;
                continue;
            } else {
                putNodePre->next = putNodeCpy->next;
                putNodeCpy->next = pre->next;
                pre->next = putNodeCpy;
            }
        }

        ListNode* res = dummyHead->next;
        delete dummyHead;

        return res;
    }
};

int main() {
    ListNode* node3 = new ListNode(3);
    ListNode* node1 = new ListNode(1, node3);
    ListNode* node2 = new ListNode(2, node1);
    ListNode* node4 = new ListNode(4, node2);

    Solution().insertionSortList(node4);
    return 0;
}