// 设计哈希集合
// https://leetcode-cn.com/leetbook/read/hash-table/xh377h/

#include <vector>
#include <set>

using namespace std;

class MyHashSet {
private:
    int M = 196613;
    vector<set<int>> hashtable;

    int hashFunc(int key) {
        return (key % M);    
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() : hashtable(M) {

    }
    
    void add(int key) {
        auto& myset = hashtable[hashFunc(key)];

        if(myset.find(key) == myset.end()) {
            myset.insert(key);
        }
    }
    
    void remove(int key) {
        auto& myset = hashtable[hashFunc(key)];

        if(myset.find(key) != myset.end()) {
            myset.erase(key);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto& myset = hashtable[hashFunc(key)];

        return myset.find(key) != myset.end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */