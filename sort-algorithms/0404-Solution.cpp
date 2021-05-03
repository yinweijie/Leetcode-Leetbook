// 1122. 数组的相对排序
// https://leetcode-cn.com/leetbook/read/sort-algorithms/o1zu22/

#include <vector>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> hashArr1, hashArr2;
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        for(auto e : arr1) {
            hashArr1.emplace(e);
            if(e > maxNum) maxNum = e;
            if(e < minNum) minNum = e;
        }
        for(auto e : arr2) {
            hashArr2.emplace(e);
        }

        int n = maxNum - minNum + 1;
        vector<int> cnt(n);
        for(auto e : arr1) {
            cnt[e - minNum]++;
        }

        int preCount = 0;
        for(auto e : arr2) {
            preCount += cnt[e - minNum];
            cnt[e - minNum] = preCount - cnt[e - minNum];
        }

        // 此时的preCount为包含在arr2中的数字个数总和
        for(int num = minNum; num <= maxNum; num++) {
            if(hashArr1.count(num) > 0 && hashArr2.count(num) <= 0) {
                preCount += cnt[num - minNum];
                cnt[num - minNum] = preCount - cnt[num - minNum];
            }
        }

        vector<int> res(arr1.size());
        for(auto e : arr1) {
            int index = cnt[e - minNum];
            res[index] = e;
            cnt[e - minNum]++;
        }

        return res;
    }
};