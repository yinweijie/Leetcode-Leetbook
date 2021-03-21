// 搜索长度未知的有序数组
// https://leetcode-cn.com/leetbook/read/binary-search/xe0sq6/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 */
class ArrayReader {
  public:
    int get(int index) const;
};

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 1;
        while(reader.get(r) < target || reader.get(r) == 2147483647) {
            r *= 2;
        }

        if(reader.get(r) == 2147483647) {
            return -1;
        }

        while(l <= r) {
            int mid = l + (r - l) / 2;

            if(reader.get(mid) == target) return mid;

            if(reader.get(mid) > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};

int main() {
    Solution();
    return 0;
}