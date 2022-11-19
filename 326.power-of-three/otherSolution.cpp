#include <unordered_set>

class Solution1 {
public:
    bool isPowerOfThree(int n) {
        std::unordered_set<int> tableSet;
        int i = 1;
        tableSet.insert(i);
        while(i <= INT_MAX / 3) {
            i *= 3;
            tableSet.insert(i);
        }
        if(tableSet.find(n) != tableSet.end()) {
            return true;
        }
        return false;
    }
};