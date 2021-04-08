// 设计哈希集合
// https://leetcode-cn.com/leetbook/read/hash-table-plus/kiv2j/

#include <set>
#include <vector>

using namespace std;

class MyHashSet {
private:
    static constexpr int M = 196613;
    vector<set<int>> hashTable;

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hashTable.resize(M);
    }
    
    void add(int key) {
        hashTable[key % M].emplace(key);
    }
    
    void remove(int key) {
        hashTable[key % M].erase(key);
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hashTable[key % M].count(key) > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */