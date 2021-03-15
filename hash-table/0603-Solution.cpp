// 两数之和 III - 数据结构设计
// https://leetcode-cn.com/leetbook/read/hash-table/xxv9we/

#include <unordered_map>
#include <vector>
#include <climits>

using namespace std;

class TwoSum {
private:
    unordered_map<int, int> hashMap;
    vector<int> vals;
    int index = 0;

public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        hashMap[number] = index++;
        vals.emplace_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if(value <= INT_MIN || value >= INT_MAX) return false;

        for(int i = 0; i < vals.size(); i++) {
            int rest = value - vals[i];

            if(hashMap.find(rest) != hashMap.end() && hashMap[rest] != i) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */