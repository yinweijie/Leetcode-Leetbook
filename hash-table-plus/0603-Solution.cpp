// 两数之和 III - 数据结构设计
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7tuar/

#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum {
private:
    vector<int> nums;
    unordered_map<int, int> hashMap;
    int index = 0;

public:
    /** Initialize your data structure here. */
    TwoSum() {

    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.emplace_back(number);
        hashMap[number] = index++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(int i = 0; i < nums.size(); i++) {
            long long rest = (long long)value - nums[i];
            if(hashMap.count(rest) > 0 && hashMap[rest] != i) {
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