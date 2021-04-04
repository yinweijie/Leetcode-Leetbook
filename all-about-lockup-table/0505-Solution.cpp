// 回旋镖的数量
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xhp45m/

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int distSqr(const vector<int>& p1, const vector<int>& p2) {
        return (p2[0] - p1[0]) * (p2[0] - p1[0]) + (p2[1] - p1[1]) * (p2[1] - p1[1]);
    }

public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int res = 0;

        for(int i = 0; i < points.size(); i++) {
            unordered_map<int, int> hashMap;

            for(int j = 0; j < points.size(); j++) {
                if(i != j) {
                    hashMap[distSqr(points[i], points[j])]++;
                }
            }

            for(auto[dist2, count] : hashMap) {
                if(count >= 2) {
                    res += count * (count - 1);
                }
            }
        }

        return res;
    }
};

int main() {
    vector<vector<int>> points {{1,1},{2,2},{3,3}};
    Solution().numberOfBoomerangs(points);
    return 0;
}