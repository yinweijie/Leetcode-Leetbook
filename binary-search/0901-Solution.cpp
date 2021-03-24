// 寻找重复数
// https://leetcode-cn.com/leetbook/read/binary-search/xe6xnr/

#include <vector>

using namespace std;

// 参考：https://leetcode-cn.com/problems/find-the-duplicate-number/solution/er-fen-fa-si-lu-ji-dai-ma-python-by-liweiwei1419/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        
        // 例如这样的数列：[1, 2, 3, 4, 5, 5, 6, 7]，目标值是5，从5开始往后的每个数i，小于等于
        // i的个数count都严格大于i，比如小于等于6的数有7个，从5前一个数开始往前的每个数i，小于等于
        // i的个数count会等于i；
        // 如果5这个数有更多重复，就需要其他数来替换，例如这样的数列：[1, 5, 3, 5, 5, 5, 6, 7]
        // 其中2和4都被替换为5了，因此从5开始往后的数i，小于等于i的个数count依旧严格大于i，但从5
        // 前一个数开始往前的每个数i，小于等于i的个数count就小于i了；
        // 因此，这两种情况可以统一。
        while(l < r) {
            int mid = l + (r - l) / 2;

            int count = 0;
            for(auto num : nums) {
                if(num <= mid) {
                    count++;
                }
            }

            if(count > mid) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return l;
    }
};