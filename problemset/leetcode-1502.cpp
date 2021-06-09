// 1502. 判断能否形成等差数列
// https://leetcode-cn.com/problems/can-make-arithmetic-progression-from-sequence/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());

        int dist = arr[1] - arr[0];
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i - 1] != dist) return false;
        }

        return true;
    }
};