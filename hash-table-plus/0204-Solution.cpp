// 设计哈希映射
// https://leetcode-cn.com/leetbook/read/hash-table-plus/kuaat/

#include <map>
#include <vector>

using namespace std;

class MyHashMap {
private:
    static constexpr int M = 196333;
    vector<map<int, int>> hashMap;

public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hashMap.resize(M);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        hashMap[key % M][key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return hashMap[key % M].find(key) != hashMap[key % M].end() ?
                hashMap[key % M][key] : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        hashMap[key % M].erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */