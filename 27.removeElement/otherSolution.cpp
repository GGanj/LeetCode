#include <vector>

class Solution1 {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int>::iterator iter = nums.begin();
        while(iter != nums.end()) {
            if(*iter != val) {
                ++iter;
            } else {
                nums.erase(iter);
            }
        }
        return nums.size();
    }
};