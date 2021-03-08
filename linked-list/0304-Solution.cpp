// 相交链表
// https://leetcode-cn.com/leetbook/read/linked-list/jjbj2/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;
        
        if(A == nullptr || B == nullptr) return nullptr;

        while(A != B) {
            A = A == nullptr ? headB : A->next;
            B = B == nullptr ? headA : B->next;
        }

        return A; // 有交点时返回交点，没有交点时返回末尾nullptr
    }
};