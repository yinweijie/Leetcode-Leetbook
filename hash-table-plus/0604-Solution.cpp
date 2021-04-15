// 四数相加 II
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x787ps/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> hashMap;

        for(int i = 0; i < nums1.size(); i++) {
            for(int j = 0; j < nums2.size(); j++) {
                hashMap[nums1[i] + nums2[j]]++;
            }
        }

        int res = 0;
        for(int i = 0; i < nums3.size(); i++) {
            for(int j = 0; j < nums4.size(); j++) {
                auto it = hashMap.find(-(nums3[i] + nums4[j]));
                if(it != hashMap.end()) {
                    res += it->second;
                }
            }
        }

        return res;
    }
};

int main() {
    vector<int> num1 {1, 2};
    vector<int> num2 {-2, 1};
    vector<int> num3 {-1, 2};
    vector<int> num4 {0, 2};
    Solution().fourSumCount(num1, num2, num3, num4);
    return 0;
}