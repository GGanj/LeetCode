#include <vector>

class Solution1 {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> res = {0};
        for(int i = 1; i <= n; ++i) {
            int j = i;
            int count = 0;
            while(j > 0) {
                j = j & (j - 1);
                ++count;
            }
            res.push_back(count);
        }
        return res;
    }
};

// low bit dynamic programing
class Solution2 {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> res = {0};
        for(int i = 1; i <= n; ++i) {
            int newBit = 1 + res[i & (i - 1)];
            res.push_back(newBit);
        }
        return res;
    }
};