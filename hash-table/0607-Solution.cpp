// 常数时间插入、删除和获取随机元素
// https://leetcode-cn.com/leetbook/read/hash-table/xx0zpt/

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class RandomizedSet {
private:
    vector<int> values;
    // <number, index>
    unordered_map<int, int> hashMap;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashMap.find(val) != hashMap.end()) return false;

        values.emplace_back(val);
        hashMap[val] = values.size() - 1;

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashMap.find(val) == hashMap.end()) return false;

        int idx = hashMap[val];

        swap(values[idx], values[values.size() - 1]);
        values.pop_back();

        hashMap[values[idx]] = idx;
        hashMap.erase(val);

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int randIndex = rand() % (values.size());
        return values[randIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */