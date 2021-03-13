// 两个列表的最小索引总和
// https://leetcode-cn.com/leetbook/read/hash-table/xhfact/

#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> hashMap;
        for(int i = 0; i < list1.size(); i++) {
            hashMap[list1[i]] = i;
        }

        vector<string> res;
        int minSum = INT_MAX;
        int sum = 0;
        for(int i = 0; i < list2.size(); i++) {
            if(hashMap.count(list2[i]) > 0) {
                sum = hashMap[list2[i]] + i;

                if(sum < minSum) {
                    res.clear();
                    res.emplace_back(list2[i]);
                } else if(sum == minSum) {
                    res.emplace_back(list2[i]);
                }

                minSum = min(sum, minSum);
            }
        }

        return res;
    }
};