// 常数时间插入、删除和获取随机元素
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x76p93/

#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> hashMap;
    vector<int> arr;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(hashMap.count(val) > 0) return false;

        hashMap[val] = arr.size();
        arr.emplace_back(val);

        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(hashMap.count(val) == 0) return false;

        int index = hashMap[val];
        hashMap[arr.back()] = index;
        hashMap.erase(val);

        swap(arr[index], arr.back());
        arr.pop_back();

        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % (arr.size());
        return arr[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */