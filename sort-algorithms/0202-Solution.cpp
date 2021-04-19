// 剑指 Offer 45. 把数组排成最小的数
// https://leetcode-cn.com/leetbook/read/sort-algorithms/oshq72/

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 此题难度在于证明。这里给出不严谨归纳
// 首先定义字符串A < B满足AB < BA；例如："30" < "4"因为"304" < "430"；注意字符串比较是逐字符按字典序比较
// 以这个规则对字符串数组进行排序，最终满足A < B < C < D的字符串拼接得到的数字ABCD一定是最小的
// 例如ACDB是小于ABCD的，因为ABCD < ACBD < ACDB，这里每一个不等号成立的原因是，根据定义B < C可以得到
// BC < CB，由B < D可以得到BD < DB，而对于位数相同的数字，比较不同的位数可以得到大小，因此ABCD < ACBD < ACDB
// 并且这里的字符串大小，实际上反应的也是数值的大小，所以ABCD < ACDB在数值上也是成立的
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strVec;
        for(auto num : nums) {
            strVec.emplace_back(to_string(num));
        }

        sort(strVec.begin(), strVec.end(), [](const string& a, const string& b) {
                return (a + b) < (b + a);
        });

        string res;
        for(auto str : strVec) {
            res += str;
        }

        return res;
    }
};