/// https://leetcode-cn.com/leetbook/read/queue-stack/kzlb5/

#include <vector>
#include <iostream>

using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int front;
    int tail;
public:
    MyCircularQueue(int k) {
        data.resize(k);
        front = -1;
        tail = -1;
    }
    
    bool enQueue(int value) {
        if(isFull()) {
            return false;
        }

        if(isEmpty()) {
            front = 0;
        }

        tail = (tail + 1) % data.size();
        data[tail] = value;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }

        if(front == tail) {
            front = -1;
            tail = -1;
            return true;
        }

        front = (front + 1) % data.size();

        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }

        return data[front];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }

        return data[tail];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((tail + 1) % data.size() == front);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */