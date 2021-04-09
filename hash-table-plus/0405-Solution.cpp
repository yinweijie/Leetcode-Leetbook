// 两个列表的最小索引总和
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7rs1h/

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

        int indexSum = INT_MAX;
        vector<string> res;
        for(int i = 0; i < list2.size(); i++) {
            if(hashMap.count(list2[i]) > 0) {
                if(hashMap[list2[i]] + i < indexSum) {
                    res.clear();
                    res.emplace_back(list2[i]);

                    indexSum = hashMap[list2[i]] + i;
                } else if(hashMap[list2[i]] + i == indexSum) {
                    res.emplace_back(list2[i]);
                }
            }
        }

        return res;
    }
};

int main() {
    vector<string> list1 {"Shogun","Tapioca Express","Burger King","KFC"};
    vector<string> list2 {"KFC","Shogun","Burger King"};
    Solution().findRestaurant(list1, list2);
    return 0;
}