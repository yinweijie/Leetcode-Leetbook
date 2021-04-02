// 两个数组的交集 II
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/fznzm/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashMap;
        for(int num : nums1) {
            hashMap[num]++;
        }

        vector<int> res;
        for(int num : nums2) {
            if(hashMap.find(num) != hashMap.end()) {
                res.emplace_back(num);
                hashMap[num]--;

                if(hashMap[num] == 0) {
                    hashMap.erase(num);
                }
            }
        }

        return res;
    }
};