// 剑指 Offer 40. 最小的 k 个数
// https://leetcode-cn.com/leetbook/read/sort-algorithms/os5lwi/

#include <vector>
#include <queue>
#include <cassert>

using namespace std;

class Solution {
private:
    class PriorityQueue {
    private:
        vector<int> data;

    public:
        int parent(int k) {
            assert(k > 0);

            return (k - 1) / 2;
        }

        int leftChild(int k) {
            return (k * 2) + 1;
        }

        int rightChild(int k) {
            return (k * 2) + 2;
        }

        int size() {
            return data.size();
        }

        void emplace(int e) {
            data.emplace_back(e);
            siftUp(data.size() - 1);
        }

        void siftUp(int k) {
            while(k > 0) {
                if(data[k] > data[parent(k)]) {
                    swap(data[k], data[parent(k)]);
                    k = parent(k);
                } else {
                    break;
                }
            }
        }

        int top() {
            return data.front();
        }

        void pop() {
            swap(data[0], data[data.size() - 1]);
            data.pop_back();
            siftDown(0);
        }

        void siftDown(int k) {
            int n = data.size();
            while(leftChild(k) <= n - 1) {
                int j = leftChild(k);
                if(j + 1 <= n - 1 && data[j + 1] > data[j]) {
                    j = j + 1;
                }

                if(data[k] > data[j]) {
                    break;
                }

                swap(data[k], data[j]);
                k = j;
            }
        }
    };

public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        // priority_queue<int> pq;
        PriorityQueue pq;

        for(auto e : arr) {
            pq.emplace(e);

            if(pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.emplace_back(pq.top());
            pq.pop();
        }

        return res;
    }
};