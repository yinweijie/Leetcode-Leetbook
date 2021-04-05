// 直线上最多的点数
// https://leetcode-cn.com/leetbook/read/all-about-lockup-table/xha3f7/

#include <vector>
#include <unordered_map>
#include <functional>
#include <iostream>

using namespace std;

class Solution {
private:
    struct HashPair {
        template <typename T1, typename T2>
        size_t operator()(const pair<T1, T2>& p) const {
            auto hash1 = hash<T1>{}(p.first);
            auto hash2 = hash<T2>{}(p.second);

            return hash1 ^ hash2;
        }
    };

    // 求最大公约数
    int gcd(int x, int y) {
        while(y != 0) {
            int rest = x % y;
            x = y;
            y = rest;
        }

        return x;
    }

public:
    int maxPoints(vector<vector<int>>& points) {
        // slot = dy / dx ==> pair(dy, dx)
        unordered_map<pair<int, int>, int, HashPair> slopCount;

        for(int i = 0; i < points.size() - 1; i++) {
            for(int j = i + 1; j < points.size(); j++) {
                int distX = points[j][0] - points[i][0];
                int distY = points[j][1] - points[i][1];
                int gcdRet = gcd(points[j][0] - points[i][0], points[j][1] - points[i][1]);

                slopCount[make_pair(distY / gcdRet, distX / gcdRet)]++;
                // cout << "dy: " << distY / gcdRet << ", dx: " << distX / gcdRet <<endl;
            }
        }
        // cout << "slogCount: " << slopCount[make_pair(1, 1)] << endl;
        for(auto it = slopCount.begin(); it != slopCount.end(); it++) {
            cout << "dy: " << it->first.first << " dx: " << it->first.second << " count: " << it->second << endl;
        }
    }
};

int main() {
    // vector<vector<int>> points {{1,1},{2,2},{3,3}};
    vector<vector<int>> points {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    Solution().maxPoints(points);
    return 0;
}