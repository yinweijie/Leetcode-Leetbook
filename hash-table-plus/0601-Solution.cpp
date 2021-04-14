// 宝石与石头
// https://leetcode-cn.com/leetbook/read/hash-table-plus/x7iknj/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hashSet;
        int res = 0;

        for(char c : jewels) {
            hashSet.emplace(c);
        }

        for(char c : stones) {
            if(hashSet.count(c) > 0) {
                res++;
            }
        }

        return res;
    }
};