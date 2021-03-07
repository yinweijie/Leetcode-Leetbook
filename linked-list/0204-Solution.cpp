// 设计链表
// https://leetcode-cn.com/leetbook/read/linked-list/jy291/

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* next;

        Node(int val_, Node* next_) : val(val_), next(next_) { }

        Node(int val_) : Node(val_, nullptr) { }

        Node() : Node(-1) { }
    };
    
    Node* dummyHead;
    int size;

public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        dummyHead = new Node();
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= size) return -1;

        Node* pre = dummyHead;
        for(int i = 0; i < index; i++) {
            pre = pre->next;
        }

        return pre->next->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* head = new Node(val, dummyHead->next);
        dummyHead->next = head;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* pre = dummyHead;
        while(pre->next != nullptr) {
            pre = pre->next;
        }

        pre->next = new Node(val);
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size) return;
        if(index < 0) index = 0;

        Node* pre = dummyHead;
        for(int i = 0; i < index; i++) {
            pre = pre->next;
        }

        Node* node = new Node(val, pre->next);
        pre->next = node;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size) return;

        Node* pre = dummyHead;
        for(int i = 0; i < index; i++) {
            pre = pre->next;
        }

        Node* toDel = pre->next;
        pre->next = toDel->next;
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

int main() {
   MyLinkedList* obj = new MyLinkedList();
//    ["MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex",
//    "deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"]
//     [[],[7],[2],[1],[3,0],[2],[6],[4],[4],[4],[5,0],[6]]
    obj->addAtHead(7);
    obj->addAtHead(2);
    obj->addAtHead(1);
    obj->addAtIndex(3, 0);
    obj->deleteAtIndex(2);
    obj->addAtHead(6);
    obj->addAtTail(4);
    obj->get(4);
    obj->addAtHead(4);
    obj->addAtIndex(5, 0);
    obj->addAtHead(6);

    return 0;
}