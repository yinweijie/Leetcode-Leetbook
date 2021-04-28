// 506. 相对名次
// https://leetcode-cn.com/leetbook/read/sort-algorithms/et905c/

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> scoreSorted = score;

        int n = scoreSorted.size();
        int h = n / 2;
        while(h >= 1) {
            for(int i = h; i < n; i++) {
                int t = scoreSorted[i];

                int j;
                for(j = i; j - h >= 0 && scoreSorted[j - h] < t; j -= h) {
                    scoreSorted[j] = scoreSorted[j - h];
                }
                scoreSorted[j] = t;
            }

            h /= 2;
        }

        unordered_map<int, string> hashMap;
        for(int i = 0; i < n; i++) {
            switch(i) {
                case 0:
                    hashMap[scoreSorted[i]] = "Gold Medal";
                    break;
                case 1:
                    hashMap[scoreSorted[i]] = "Silver Medal";
                    break;
                case 2:
                    hashMap[scoreSorted[i]] = "Bronze Medal";
                    break;
                default:
                    hashMap[scoreSorted[i]] = to_string(i + 1);
            }
        }

        vector<string> res;
        for(auto e : score) {
            res.emplace_back(hashMap[e]);
        }

        return res;
    }
};

int main() {
    vector<int> score {5,4,3,2,1};

    Solution().findRelativeRanks(score);
    return 0;
}