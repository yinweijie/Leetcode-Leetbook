// 设计哈希映射
// https://leetcode-cn.com/leetbook/read/hash-table/xhqwd3/

#include <vector>
#include <map>

using namespace std;

class MyHashMap {
private:
    int M = 1572869;
    vector<map<int, int>> hashtable;

    int hashFunc(int key) {
        return (key % M);
    }

public:
    /** Initialize your data structure here. */
    MyHashMap() : hashtable(M) {

    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto& mp = hashtable[hashFunc(key)];

        mp[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto& mp = hashtable[hashFunc(key)];
        auto it = mp.find(key);

        if(it != mp.end()) {
            return it->second;
        }

        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto& mp = hashtable[hashFunc(key)];
        auto it = mp.find(key);

        if(it != mp.end()) {
            mp.erase(it);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */