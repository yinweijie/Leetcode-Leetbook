// 面试题 16.15. 珠玑妙算
// https://leetcode-cn.com/problems/master-mind-lcci/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> masterMind(string solution, string guess) {
        unordered_map<int, int> fakeGuess, trueGuess;
        unordered_map<int, int> cnt;

        int n = solution.size();

        for(int i = 0; i < n; i++) {
            cnt[solution[i]]++;
        }

        for(int i = 0; i < n; i++) {
            // 真猜中
            if(solution[i] == guess[i]) {
                trueGuess[guess[i]]++;

                // 去掉和真猜中重合的那个伪猜中
                if(fakeGuess.count(guess[i]) > 0 && cnt.count(guess[i]) == 0) {
                    fakeGuess[guess[i]]--;
                    if(fakeGuess[guess[i]] == 0) {
                        fakeGuess.erase(guess[i]);
                    }
                }

                // 真猜中消掉cnt里一个对应计数
                if(cnt.count(guess[i]) > 0 && cnt[guess[i]] > 0) {
                    cnt[guess[i]]--;

                    if(cnt[guess[i]] == 0) {
                        cnt.erase(guess[i]);
                    }
                }
            } else { // 考察是否伪猜中
                if(cnt.count(guess[i]) > 0 && cnt[guess[i]] > 0) {
                    fakeGuess[guess[i]]++;
                    cnt[guess[i]]--;

                    if(cnt[guess[i]] == 0) {
                        cnt.erase(guess[i]);
                    }
                }
            }
        }

        vector<int> res;
        res.emplace_back(0);
        res.emplace_back(0);

        if(trueGuess.size() > 0) {
            for(auto[c, freq] : trueGuess) {
                res[0] += freq;
            }
        }
        if(fakeGuess.size() > 0) {
            for(auto[c, freq] : fakeGuess) {
                res[1] += freq;
            }
        }

        return res;
    }
};