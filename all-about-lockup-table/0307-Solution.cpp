// 根据字符出现频率排序
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/fc4ic/

#include <string>
#include <unordered_map>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        if(s.empty()) return string();

        unordered_map<char, int> hashMap;
        for(char c : s) {
            hashMap[c]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto[e, freq] : hashMap) {
            pq.emplace(make_pair(freq, e));
        }

        string res(s);
        int i = 0;
        while(!pq.empty()) {
            auto[freq, e] = pq.top();
            pq.pop();

            while(freq > 0) {
                res[i++] = e;
                freq--;
            }
        }

        return res;
    }
};