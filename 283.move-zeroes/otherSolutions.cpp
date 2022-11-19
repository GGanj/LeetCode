#include <vector>

class Solution1 {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::vector<int>::iterator iterSlow = nums.begin(), iterFast = nums.begin();
        while(iterSlow != nums.end() && iterFast != nums.end()) {
            if(*iterFast == 0 ) {
                ++iterFast;
                continue;
            }
            if(*iterSlow != 0) {
                ++iterSlow;
                continue;
            }
            if(iterFast < iterSlow) {
                iterFast = iterSlow + 1;
                continue;
            }
            *iterSlow = *iterFast;
            *iterFast = 0;
            ++iterSlow;
        }
        while(iterSlow < iterFast - 1) {
            *iterSlow = 0;
            ++iterSlow;
        }
    }
};

class Solution2 {
public:
    void moveZeroes(std::vector<int>& nums) {
        std::vector<int>::iterator iterSlow = nums.begin(), iterFast = nums.begin();
        while(iterFast != nums.end()) {
            if(*iterFast != 0) {
                *iterSlow = *iterFast;
                ++iterSlow;
            }
            ++iterFast;
        }
        while(iterSlow != nums.end()) {
            *iterSlow = 0;
            ++iterSlow;
        }
    }
};