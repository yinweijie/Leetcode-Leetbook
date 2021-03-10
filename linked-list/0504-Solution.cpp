// 设计链表
// https://leetcode-cn.com/leetbook/read/linked-list/fabl3/

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* pre;
        Node* next;

        Node(int val_, Node* pre_, Node* next_) : val(val_), pre(pre_), next(next_){ }

        Node(int val_) : Node(val_, nullptr, nullptr) { }

        Node() : Node(-1) { }
    };

    Node* head;
    Node* tail;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* pre = head;
        for(int i = 0; i < index; i++) {
            pre = pre->next;
        }

        return pre->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val, head, head->next);
        head->next = node;
        node->next->pre = node;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val, tail->pre, tail);
        tail->pre->next = node;
        tail->pre = node;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;

        Node* pre = head;
        for(int i = 0; i < index; i++) {
            pre = pre->next;
        }

        Node* node = new Node(val, pre, pre->next);
        pre->next = node;
        node->next->pre = node;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        Node* pre = head;
        for(int i = 0; i < index; i++) {
            pre = pre->next;
        }

        Node* toDel = pre->next;
        pre->next = toDel->next;
        toDel->next->pre = pre;
        delete toDel;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */