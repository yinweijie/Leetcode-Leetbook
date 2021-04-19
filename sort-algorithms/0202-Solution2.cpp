// 剑指 Offer 45. 把数组排成最小的数
// https://leetcode-cn.com/leetbook/read/sort-algorithms/oshq72/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 用冒泡排序实现
class Solution {
private:
    bool compare(const string& a, const string& b) {
        return (a + b) < (b + a);
    }

    void bubbleSort(vector<string>& strVec) {
        int n = strVec.size();

        // [n - i, n)已排好序，即有i个已排好序
        // 进行n - 1轮循环即可，每一轮放一个数
        for(int i = 0; i + 1 < n; ) {
            // 在n - i - 1放置合适元素
            int swappedIndex = 0;

            for(int j = 0; j + 1 <= n - i - 1; j++) {
                if(!compare(strVec[j], strVec[j + 1])) {
                    swap(strVec[j], strVec[j + 1]);
                    swappedIndex = j + 1;
                }
            }

            if(swappedIndex == 0) break;

            i = n - swappedIndex; // 有n - swappedIndex已排好序
        }
    }

public:
    string minNumber(vector<int>& nums) {
        vector<string> strVec;
        for(auto num : nums) {
            strVec.emplace_back(to_string(num));
        }

        bubbleSort(strVec);

        string res;
        for(auto str : strVec) {
            res += str;
        }

        return res;
    }
};