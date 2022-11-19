#include <unordered_map>

class Solution1 {
public:
    bool isHappy(int n) {
        std::unordered_map<int, int> trace;
        ++trace[n];
        while(n != 1) {
            int newNum = 0, remainder = 0;
            while(n != 0) {
                remainder = n % 10;
                remainder *= remainder;
                newNum += remainder;
                n /= 10;
            }
            if(trace[newNum]) {
                return false;
            } else {
                ++trace[newNum];
                n = newNum;
            }
        }
        return true;
    }
};

class Solution {
public:
    int getNext(int n) {
        int newNum = 0, remainder = 0;
        while(n != 0) {
            remainder = n % 10;
            remainder *= remainder;
            newNum += remainder;
            n /= 10;
        }
        return newNum;  
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        while(fast != 1) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
            if(slow == fast) {
                return false;
            }
        }
        return true;
    }
};