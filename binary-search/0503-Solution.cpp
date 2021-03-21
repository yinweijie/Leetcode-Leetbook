// 找到 K 个最接近的元素
// https://leetcode-cn.com/leetbook/read/binary-search/xeve4m/

#include <vector>
#include <iostream>

using namespace std;

// 参考：https://leetcode-cn.com/problems/find-k-closest-elements/solution/pai-chu-fa-shuang-zhi-zhen-er-fen-fa-python-dai-ma/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0, r = arr.size() - k;

        while(l < r) {
            int mid = l + (r - l) / 2;

            // 注意这里不能写成abs(x - arr[mid]) <= abs(arr[mid + k] - x)
            // 必须分类讨论然后合并重合的可能性
            // 例如：[2, 2, 2, 3] ==> [mid, ..., mid + k, x]
            // 满足abs(x - arr[mid]) <= abs(arr[mid + k] - x)
            // 但并不满足x - arr[mid] <= arr[mid + k] - x
            if(x - arr[mid] <= arr[mid + k] - x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};

int main() {
    vector<int> arr {1,1,2,2,2,2,2,3,3};
    vector<int> res = Solution().findClosestElements(arr, 3, 3);
    for(auto num : res) {
        cout << num << endl;
    }
    return 0;
}