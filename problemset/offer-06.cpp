// 剑指 Offer 06. 从尾到头打印链表
// https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/

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
private:
    void reversePrintR(ListNode* node) {
        if(node == nullptr) return;

        reversePrintR(node->next);

        res.emplace_back(node->val);
    }

    vector<int> res;

public:
    vector<int> reversePrint(ListNode* head) {
        reversePrintR(head);

        return res;
    }
};