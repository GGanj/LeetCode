#include <vector>

class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        if(x == 0) {
            return true;
        }
        std::vector<int> numsArr;
        while(x != 0) {
            numsArr.push_back(x % 10);
            x /= 10;
        }
        std::vector<int>::iterator iter1 = numsArr.begin(), iter2 = numsArr.end() - 1;
        while(iter1 <= iter2) {
            if(*iter1 != *iter2) {
                return false;
            }
            ++iter1;
            --iter2;
        }
        return true;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        if(x == 0) {
            return true;
        }
        int tmp = 0;
        while(x > tmp) {
            tmp = tmp * 10 + x % 10;
            if(x == tmp) {
                return true;
            }
            x /= 10;
            if(x == tmp) {
                return true;
            }
        }
        return false;
    }
};