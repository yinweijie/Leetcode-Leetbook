// 宝石与石头
// https://leetcode-cn.com/leetbook/read/hash-table/xx2a0c/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> hashSet;
        int res = 0;

        for(char c : jewels) {
            hashSet.insert(c);
        }

        for(char c : stones) {
            if(hashSet.find(c) != hashSet.end()) {
                res++;
            }
        }

        return res;
    }
};